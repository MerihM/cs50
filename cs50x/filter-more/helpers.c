#include "helpers.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

BYTE avg(BYTE r, BYTE g, BYTE b);
void get_3_x_3(int n, int k, int height, int width, int *empty_ctr, RGBTRIPLE img[height][width],
               RGBTRIPLE blur_arr[3][3]);
int check_bound(int a, int b, int height, int width);
RGBTRIPLE blur_avg(int arr_size, RGBTRIPLE blur_arr[arr_size][arr_size], int *empty_ctr);
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            BYTE new = avg(image[i][j].rgbtRed, image[i][j].rgbtGreen, image[i][j].rgbtBlue);
            image[i][j].rgbtRed = image[i][j].rgbtGreen = image[i][j].rgbtBlue = new;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        int start = 0, end = width - 1;
        while (end >= start)
        {
            RGBTRIPLE temp = image[i][start];
            image[i][start] = image[i][end];
            image[i][end] = temp;
            start++;
            end--;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    // Make copy of original image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int *empty_ctr = malloc(sizeof(int));
            *empty_ctr = 0;
            RGBTRIPLE blur_arr[3][3];
            // Get 3x3 grid around pixel at position image[i][j]
            get_3_x_3(i, j, height, width, empty_ctr, copy, blur_arr);
            // Set pixel at image[i][j] to average of 3x3 grid
            image[i][j] = blur_avg(3, blur_arr, empty_ctr);
            free(empty_ctr);
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    int xr, xg, xb, yr, yg, yb;
    xr = xg = xb = yr = yg = yb = 0;
    int Gx_kernel[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int Gy_kernel[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    RGBTRIPLE copy[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            for (int n = -1; n < 2; n++)
            {
                for (int k = -1; k < 2; k++)
                {
                    if (i + n < 0 || i + n > height - 1 || j + k < 0 || j + k > width - 1)
                    {
                        continue;
                    }
                    else
                    {
                        xr += copy[i + n][j + k].rgbtRed * Gx_kernel[n + 1][k + 1];
                        xg += copy[i + n][j + k].rgbtGreen * Gx_kernel[n + 1][k + 1];
                        xb += copy[i + n][j + k].rgbtBlue * Gx_kernel[n + 1][k + 1];
                        yr += copy[i + n][j + k].rgbtRed * Gy_kernel[n + 1][k + 1];
                        yg += copy[i + n][j + k].rgbtGreen * Gy_kernel[n + 1][k + 1];
                        yb += copy[i + n][j + k].rgbtBlue * Gy_kernel[n + 1][k + 1];
                    }
                }
            }

            int sobel_operator[3];

            sobel_operator[0] = round(sqrt(xr * xr + yr * yr));
            sobel_operator[1] = round(sqrt(xg * xg + yg * yg));
            sobel_operator[2] = round(sqrt(xb * xb + yb * yb));

            for (int n = 0; n < 3; n++)
            {
                if (sobel_operator[n] > 255)
                {
                    sobel_operator[n] = 255;
                }
            }

            image[i][j].rgbtRed = sobel_operator[0];
            image[i][j].rgbtGreen = sobel_operator[1];
            image[i][j].rgbtBlue = sobel_operator[2];
            xr = xg = xb = yr = yg = yb = 0;
        }
    }
    return;
}

BYTE avg(BYTE r, BYTE g, BYTE b)
{
    // Find average value of red, green and blue
    return round(((r + g + b) / 3.0));
}

void get_3_x_3(int n, int k, int height, int width, int *empty_ctr, RGBTRIPLE img[height][width],
               RGBTRIPLE nine_arr[3][3])
{
    int arr_size = 3;

    // Initialize new empty RGBTRIPLE variable, whos members are set to 0;
    RGBTRIPLE empty;
    empty.rgbtRed = 0;
    empty.rgbtGreen = 0;
    empty.rgbtBlue = 0;
    int fi = -1;
    for (int i = 0; i < arr_size; i++)
    {
        int fj = -1;
        for (int j = 0; j < arr_size; j++)
        {
            // t1 and t2 represent pixel position, shifted by fi and fj, in original image
            int t1 = n + fi, t2 = k + fj;
            // If values t1 and t2 are out of bound, set position in array to empty, and increment
            // counter of empty places
            if (check_bound(t1, t2, height, width))
            {
                nine_arr[i][j] = empty;
                *empty_ctr += 1;
            }
            // Set pixel at nine_arr[i][j] to pixel at original position img[t1][t2]
            else
            {
                nine_arr[i][j] = img[t1][t2];
            }
            fj++;
        }
        fi++;
    }
}
// Checks if a and b are inside bounds of picture
int check_bound(int a, int b, int height, int width)
{
    return (((a < 0) || (b < 0)) || ((a > height - 1) || (b > width - 1)));
}
// Finds average value of 3x3 grid of pixels and returns new value
RGBTRIPLE blur_avg(int arr_size, RGBTRIPLE nine_arr[arr_size][arr_size], int *empty_ctr)
{
    RGBTRIPLE new;
    int red = 0, green = 0, blue = 0, div_by = (arr_size * arr_size - *empty_ctr);
    for (int i = 0; i < arr_size; i++)
    {
        for (int j = 0; j < arr_size; j++)
        {
            // Sums up red, green and blue values of pixels in 3x3 grid
            red += nine_arr[i][j].rgbtRed;
            green += nine_arr[i][j].rgbtGreen;
            blue += nine_arr[i][j].rgbtBlue;
        }
    }
    new.rgbtRed = round((double) red / (double) div_by);
    new.rgbtGreen = round((double) green / (double) div_by);
    new.rgbtBlue = round((double) blue / (double) div_by);
    return new;
}

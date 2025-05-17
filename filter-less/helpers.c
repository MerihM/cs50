#include "helpers.h"
#include <math.h>

BYTE avg(BYTE r, BYTE g, BYTE b);
int calc_sepia(RGBTRIPLE pixel, char flag);
int to_255(int b);
RGBTRIPLE blur_avg(int arr_size, RGBTRIPLE blur_arr[arr_size][arr_size], int empty_ctr);

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            BYTE newValue = avg(image[i][j].rgbtRed, image[i][j].rgbtGreen, image[i][j].rgbtBlue);
            image[i][j].rgbtRed = newValue;
            image[i][j].rgbtGreen = newValue;
            image[i][j].rgbtBlue = newValue;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sepRed = to_255(calc_sepia(image[i][j], 'r'));
            int sepGreen = to_255(calc_sepia(image[i][j], 'g'));
            int sepBlue = to_255(calc_sepia(image[i][j], 'b'));

            image[i][j].rgbtRed = sepRed;
            image[i][j].rgbtGreen = sepGreen;
            image[i][j].rgbtBlue = sepBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        int start = 0;
        int end = width - 1;

        while (end >= start)
        {
            RGBTRIPLE temp_pixel = image[i][start];
            image[i][start] = image[i][end];
            image[i][end] = temp_pixel;
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
            int arr_size = 3;
            int empty_ctr = 0;
            RGBTRIPLE blur_arr[arr_size][arr_size];
            RGBTRIPLE empty, avg;
            empty.rgbtRed = 0;
            empty.rgbtGreen = 0;
            empty.rgbtBlue = 0;
            int i_flag = -1;
            for (int n = 0; n < arr_size; n++)
            {
                int j_flag = -1;
                for (int k = 0; k < arr_size; k++)
                {
                    int t1 = i + i_flag, t2 = j + j_flag;
                    if (((t1 < 0) || (t2 < 0)) || ((t1 > height - 1) || (t2 > width - 1)))
                    {
                        blur_arr[n][k] = empty;
                        empty_ctr++;
                    }
                    else
                    {
                        blur_arr[n][k] = copy[t1][t2];
                    }
                    j_flag++;
                }
                i_flag++;
            }
            avg = blur_avg(arr_size, blur_arr, empty_ctr);
            image[i][j] = avg;
        }
    }
    return;
}

BYTE avg(BYTE r, BYTE g, BYTE b)
{
    BYTE test = round(((r + g + b) / 3.0));
    return test;
}

int calc_sepia(RGBTRIPLE pixel, char flag)
{
    switch (flag)
    {
        case 'r':
            return round(0.393 * pixel.rgbtRed + 0.769 * pixel.rgbtGreen + 0.189 * pixel.rgbtBlue);
            break;
        case 'g':
            return round(0.349 * pixel.rgbtRed + 0.686 * pixel.rgbtGreen + 0.168 * pixel.rgbtBlue);
            break;
        case 'b':
            return round(0.272 * pixel.rgbtRed + 0.534 * pixel.rgbtGreen + 0.131 * pixel.rgbtBlue);
            break;
        default:
            return 0;
            break;
    }
}

int to_255(int b)
{
    int temp = b;
    if (temp > 255)
        temp = 255;
    return temp;
}

RGBTRIPLE blur_avg(int arr_size, RGBTRIPLE blur_arr[arr_size][arr_size], int empty_ctr)
{
    RGBTRIPLE new;
    int red = 0, green = 0, blue = 0;
    for (int i = 0; i < arr_size; i++)
    {
        for (int j = 0; j < arr_size; j++)
        {
            red += blur_arr[i][j].rgbtRed;
            green += blur_arr[i][j].rgbtGreen;
            blue += blur_arr[i][j].rgbtBlue;
        }
    }
    new.rgbtRed = round((double) red / (double) (arr_size * arr_size - empty_ctr));
    new.rgbtGreen = round((double) green / (double) (arr_size * arr_size - empty_ctr));
    new.rgbtBlue = round((double) blue / (double) (arr_size * arr_size - empty_ctr));
    return new;
}

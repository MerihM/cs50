#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
typedef uint8_t BYTE;

int check_jpeg(BYTE *buf);
int main(int argc, char *argv[])
{
    // Check if there is one argument
    if (argc != 2)
    {
        printf("Usage: recover.c [forensic image]");
        return 1;
    }

    char *file = argv[1];
    // Open file from argument
    FILE *input = fopen(file, "r");
    // Check if file is opened
    if (input == NULL)
    {
        printf("Could not open %s.", file);
        return 1;
    }
    int file_no = 0, fat_size = 512;
    BYTE buffer[fat_size];
    FILE *output = NULL;
    char next_file[8];

    // Read bytes of memory
    while (fread(&buffer, sizeof(BYTE) * fat_size, 1, input))
    {
        BYTE *jpeg_check_buffer = malloc(4 * sizeof(BYTE));
        // Set first 4 bytes of buffer to jpeg_check_buffer
        for (int i = 0; i < 4; i++)
        {
            jpeg_check_buffer[i] = buffer[i];
        }
        // Check if bytes that are being read, are jpg format
        if (check_jpeg(jpeg_check_buffer))
        {
            // If there is opened output, close it
            if (output != NULL)
            {
                fclose(output);
            }
            // Open new output file to write in
            sprintf(next_file, "%03d.jpg", file_no++);
            output = fopen(next_file, "w");
        }
        // Write in output file if it's opened
        if (output != NULL)
            fwrite(&buffer, sizeof(BYTE) * 512, 1, output);

        // Free memory allocated for jpeg_check_buffer;
        free(jpeg_check_buffer);
    }

    // Close input
    fclose(input);
    // Close output if it's opened
    if (output != NULL)
        fclose(output);
    return 0;
}

// Function to check if first four bytes of buffer are jpg
int check_jpeg(BYTE *buf)
{
    // First three signature bytes of jpg
    int jpeg_sign[] = {0xff, 0xd8, 0xff};
    for (int i = 0; i < 3; i++)
    {
        if (buf[i] != jpeg_sign[i])
            return 0;
    }
    // Check fourth signature byte of jpg
    switch (buf[3])
    {
        case 0xe0:
        case 0xe1:
        case 0xe2:
        case 0xe3:
        case 0xe4:
        case 0xe5:
        case 0xe6:
        case 0xe7:
        case 0xe8:
        case 0xe9:
        case 0xea:
        case 0xeb:
        case 0xec:
        case 0xed:
        case 0xee:
        case 0xef:
            return 1;
            break;
        default:
            return 0;
            break;
    }
}

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char getNewLetter(char c, int key);
int main(int argc, string argv[])
{

    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    for (int i = 0; argv[1][i] != '\0'; i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    int key = atoi(argv[1]);
    string plaintext = get_string("plaintext: ");
    if (key > 25)
    {
        key = ((key % 26));
    }
    for (int i = 0, len = strlen(plaintext); i < len; i++)
    {
        if (!isalpha(plaintext[i]))
        {
            continue;
        }
        if (isupper(plaintext[i]))
        {
            plaintext[i] = toupper(getNewLetter(plaintext[i], key));
        }
        else
        {
            plaintext[i] = (getNewLetter(plaintext[i], key));
        }
    }
    printf("ciphertext: %s\n", plaintext);
}

char getNewLetter(char c, int key)
{
    if (c + key > 'z')
    {
        return ('a' + ((c + key) - 'z' - 1));
    }
    return (c + key);
}

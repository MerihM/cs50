#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

const string alphabet = "abcdefghijklmnopqrstuvwxyz";
const int len = 26;

void errorMsg();
int checkArgs(int c, string v[]);
string convertToLower(string s);
char getEncodedLetter(char c, string key);
int main(int argc, string argv[])
{
    if (checkArgs(argc, argv))
    {
        return 1;
    }
    string plaintext = get_string("plaintext: ");
    string key = convertToLower(argv[1]);
    for (int i = 0; i < strlen(plaintext); i++)
    {
        if (isalpha(plaintext[i]))
        {
            if (isupper(plaintext[i]))
            {
                plaintext[i] = toupper(getEncodedLetter(tolower(plaintext[i]), key));
            }
            else
            {
                plaintext[i] = getEncodedLetter(plaintext[i], key);
            }
        }
    }
    printf("ciphertext: %s\n", plaintext);
}
void errorMsg()
{
    printf("Usage: ./substitution key\n");
}

int checkArgs(int c, string v[])
{
    char keyCopy[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
                      'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    int ctr = 0;
    if (c != 2)
    {
        errorMsg();
        return 1;
    }
    if (strlen(v[1]) != 26)
    {
        errorMsg();
        return 1;
    }
    for (int i = 0; i < len; i++)
    {
        if (!isalpha(v[1][i]))
        {
            errorMsg();
            return 1;
        }
        for (int j = 0; j < len; j++)
        {
            if (tolower(v[1][i]) == keyCopy[j])
            {
                keyCopy[j] = toupper(keyCopy[j]);
            }
        }
    }
    for (int i = 0; i < len; i++)
    {
        if (islower(keyCopy[i]))
        {
            ctr++;
        }
    }
    if (ctr != 0)
    {
        errorMsg();
        return 1;
    }
    return 0;
}
string convertToLower(string s)
{
    for (int i = 0; i < len; i++)
    {
        if (isupper(s[i]))
        {
            s[i] = tolower(s[i]);
        }
    }
    return s;
}
char getEncodedLetter(char c, string key)
{
    for (int i = 0; i < len; i++)
    {
        if (alphabet[i] == c)
        {
            return key[i];
        }
    }
    return 'a';
}

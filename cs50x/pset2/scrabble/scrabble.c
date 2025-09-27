#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int getWordScore(string word);
int getLetterScore(char letter);
int main()
{
    string player1 = get_string("Player 1: ");
    string player2 = get_string("Player 2: ");
    int player1Sum = getWordScore(player1);
    int player2Sum = getWordScore(player2);
    if (player1Sum > player2Sum)
    {
        printf("Player 1 wins!\n");
    }
    else if (player2Sum > player1Sum)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}
int getWordScore(string word)
{
    int sum = 0;
    int len = strlen(word);
    for (int i = 0; i < len; i++)
    {
        sum += getLetterScore(word[i]);
    }
    return sum;
}
int getLetterScore(char letter)
{
    switch (tolower(letter))
    {
        case 'a':
        case 'e':
        case 'i':
        case 'l':
        case 'n':
        case 'o':
        case 'r':
        case 's':
        case 't':
        case 'u':
            return 1;
            break;
        case 'd':
        case 'g':
            return 2;
            break;
        case 'b':
        case 'c':
        case 'm':
        case 'p':
            return 3;
            break;
        case 'f':
        case 'h':
        case 'v':
        case 'w':
        case 'y':
            return 4;
            break;
        case 'k':
            return 5;
            break;
        case 'j':
        case 'x':
            return 8;
            break;
        case 'q':
        case 'z':
            return 10;
            break;
        default:
            return 0;
            break;
    }
}

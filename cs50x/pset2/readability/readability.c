#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int endOfSentence(char c);
void getCounters(double ctrs[], string text);
void gradeLevel(double lvl);
int main(void)
{
    string text = get_string("Text: ");
    // Array that represents, in order, number of letters, number of words, and number of sentences.
    double counters[] = {0.0, 0.0, 0.0};
    double L, S, CLI;
    getCounters(counters, text);
    L = ((counters[0]) / (counters[1])) * 100.0;
    S = ((counters[2]) / (counters[1])) * 100.0;
    CLI = round((0.0588 * L) - (0.296 * S) - 15.8);
    gradeLevel(CLI);
}

int endOfSentence(char c)
{
    if (((c == '.') || (c == '!') || (c == '?')))
    {
        return 1;
    }
    return 0;
}
void getCounters(double ctrs[], string text)
{
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (isalnum(text[i]))
        {
            ctrs[0]++;
        }
        else if (endOfSentence(text[i]))
        {
            if (i + 1 == len)
            {
                ctrs[1]++;
            }
            if (endOfSentence(text[i - 1]))
            {
                continue;
            }
            ctrs[2]++;
        }
        else if (isspace(text[i]))
        {
            if (isspace(text[i - 1]))
            {
                continue;
            }
            ctrs[1]++;
        }
    }
}

void gradeLevel(double lvl)
{
    int readingLvl = (int) lvl;
    if (readingLvl > 16)
    {
        readingLvl = 20;
    }
    printf("%i\n", readingLvl);
    switch ((int) readingLvl)
    {
        case 20:
            printf("Grade 16+\n");
            break;
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        case 11:
        case 12:
        case 13:
        case 14:
        case 15:
        case 16:
            printf("Grade %i\n", (int) lvl);
            break;
        default:
            printf("Before Grade 1\n");
            break;
    }
}

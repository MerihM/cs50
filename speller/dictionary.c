// Implements a dictionary's functionality
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// Number is 26 * 27 * 27, (26 letters in first position, 26 letters and apostrophe in positions 2
// and 3)
const unsigned int N = 18954;
unsigned int table_size = 0;

// Definition of function to set all members of hash table to NULL
void set_table();
node *new_node(const char *word);
bool check_words(const char *first, const char *second);

// Hash table
node *table[N];

// Function that sets all members of hash table to NULL
void set_table()
{
    for (int i = 0; i < N; i++)
        table[i] = NULL;
}

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // Find hash
    int pos = hash(word);
    // Set temp to position in table
    node *temp = table[pos];
    // While temp is not NULL, check words
    while (temp != NULL)
    {
        // If words are same, return true
        if (check_words(temp->word, word))
            return true;
        // If words are not the same, go to next node
        temp = temp->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // Set initial value to 0
    unsigned int sum = 0;
    // Check first three letters
    for (int i = 0; i < 3; i++)
    {
        // If word is shorter than three letters break out of loop
        if (word[i] == '\0')
        {
            break;
        }
        // If letter is apostrophe, add 26 to the sum
        if (word[i] == '\'')
        {
            sum += 26;
            continue;
        }
        // Convert letter to uppercase and add letters position to sum
        sum += toupper(word[i]) - 'A';
    }
    return sum;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // Open dictionary
    FILE *dict = fopen(dictionary, "r");
    // Return false if dictionary fails to load
    if (dict == NULL)
        return false;
    // Set hash table
    set_table();
    char letter;
    char word[LENGTH + 1];
    int index = 0;
    // Read words from dictionary
    while (fread(&letter, sizeof(char), 1, dict))
    {
        // Handle end of the word
        if (isalpha(letter) || letter == '\'')
        {
            word[index] = letter;
            index++;
        }
        // Handle is not end of the word
        else
        {
            // Set end to terminator character
            word[index] = '\0';
            // Reset index
            index = 0;
            table_size++;
            // Allocate new node
            node *new_word = new_node(word);
            // Find hash
            int pos = hash(word);
            // Store node in hash table
            if (table[pos] == NULL)
            {
                table[pos] = new_word;
            }
            else
            {
                node *temp = table[pos];
                while (temp->next != NULL)
                    temp = temp->next;
                temp->next = new_word;
            }
        }
    }
    fclose(dict);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return table_size;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // Check whole list
    for (int i = 0; i < N; i++)
    {
        // Set current and next to table[i]
        node *curr = table[i];
        node *next = table[i];

        // While current in not NULL, free node
        while (curr != NULL)
        {
            // Next will be next of current
            next = curr->next;
            // Free current
            free(curr);
            // Current will become next
            curr = next;
        }
    }
    return true;
}

// Allocate new node and set word
node *new_node(const char *word)
{
    node *new = malloc(sizeof(node));
    // Set next node to NULL
    new->next = NULL;
    int i = 0;
    // Copy word to new->word
    while (word[i] != '\0')
    {
        new->word[i] = word[i];
        i++;
    }
    // Set terminator character to the end
    new->word[i] = '\0';
    return new;
}

bool check_words(const char *first, const char *second)
{
    int i = 0;
    // While it's not end of either word, check if letters are same
    while (first[i] != '\0' && second[i] != '\0')
    {
        // If letters are not same, return false
        if (tolower(first[i]) != tolower(second[i]))
            return false;
        // I'm using i because I don't want to increment pointers, I'll screw up something
        i++;
    }
    return (first[i] == second[i]);
}

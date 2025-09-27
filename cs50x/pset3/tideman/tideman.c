#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
} pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);
void initialize_preferences(void);
int number_of_pairs(int n);
int diff(int w, int l);
void print_pairs(void);
bool check_loop(int head, int curr);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Initializes preferences matrix
    initialize_preferences();

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i], name) == 0)
        {
            ranks[rank] = i;
            return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    int ptr1 = 0;
    while (ptr1 != candidate_count)
    {
        for (int i = ptr1 + 1; i < candidate_count; i++)
        {
            preferences[ranks[ptr1]][ranks[i]]++;
        }
        ptr1++;
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    pair_count = number_of_pairs(candidate_count - 1);
    int ctr = 0, tie = 0;
    while (ctr != pair_count)
    {
        for (int i = 0; i < candidate_count; i++)
        {
            for (int j = i + 1; j < candidate_count; j++)
            {
                pair p;
                if (preferences[i][j] == preferences[j][i])
                {
                    tie++;
                    ctr++;
                    continue;
                }
                else if (preferences[i][j] > preferences[j][i])
                {
                    p.winner = i;
                    p.loser = j;
                }
                else
                {
                    p.loser = i;
                    p.winner = j;
                }
                pairs[ctr] = p;
                ctr++;
            }
        }
    }
    pair_count -= tie;
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    for (int i = 0; i < pair_count - 1; i++)
    {
        for (int j = i + 1; j < pair_count; j++)
        {
            int diff1 = diff(pairs[i].winner, pairs[i].loser);
            int diff2 = diff(pairs[j].winner, pairs[j].loser);
            if (diff1 < diff2)
            {
                pair temp;
                temp.winner = pairs[i].winner;
                temp.loser = pairs[i].loser;
                pairs[i].winner = pairs[j].winner;
                pairs[i].loser = pairs[j].loser;
                pairs[j].winner = temp.winner;
                pairs[j].loser = temp.loser;
            }
        }
    }
    return;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    // set locked according to pairs arr
    for (int i = 0; i < pair_count; i++)
    {
        locked[pairs[i].winner][pairs[i].loser] = check_loop(pairs[i].winner, pairs[i].loser);
    }
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            if (locked[i][j])
            {
                printf("%i ", 1);
            }
            else
            {
                printf("%i ", 0);
            }
        }
        printf("\n");
    }
    return;
}

// Print the winner of the election
void print_winner(void)
{
    // source is node which doesn't have edges pointing to it
    int winners[candidate_count];
    for (int i = 0; i < candidate_count; i++)
    {
        int ctr = 0;
        for (int j = 0; j < candidate_count; j++)
        {
            if (locked[j][i])
            {
                ctr++;
            }
        }
        winners[i] = ctr;
    }
    int min = winners[0];
    for (int i = 1; i < candidate_count; i++)
    {
        if (winners[i] < min)
        {
            min = winners[i];
        }
    }
    for (int i = 0; i < candidate_count; i++)
    {
        if (winners[i] == min)
        {
            printf("%s\n", candidates[i]);
        }
    }
    return;
}

void initialize_preferences(void)
{
    // Sets every member to 0
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            preferences[i][j] = 0;
        }
    }
}

int number_of_pairs(int n)
{
    if (n == 1)
    {
        return 1;
    }
    return (n + number_of_pairs(n - 1));
}

int diff(int w, int l)
{
    return (preferences[w][l] - preferences[l][w]);
}
void print_pairs(void)
{
    for (int i = 0; i < pair_count; i++)
    {
        printf("Pair %i: %i - %i\n", i + 1, pairs[i].winner, pairs[i].loser);
        // printf("Difference: %i\n", diff(pairs[i].winner, pairs[i].loser));
    }
}

bool check_loop(int head, int curr)
{
    if (head == curr)
    {
        return false;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        if (locked[curr][i])
        {
            if (!check_loop(head, i))
            {
                return false;
            }
        }
    }
    return true;
}

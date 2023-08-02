// Harsh - DSA- Assignment 4

#include <stdio.h>
#include <stdlib.h>

// First hash function: h1(k) = k mod M
int hash1(int k, int M) 
{
    return k % M;
}

// Second hash function: h2(k) = R - (k mod R)
int hash2(int k, int R) 
{
    return R - (k % R);
}

// Function to create and fill the hash table
void hashInit(int* hashTable, int* input, int M, int R)
{
    for (int i = 0; i < M; i++)
    {
        hashTable[i] = -1; // Initialize the hash table with -1 to indicate empty slots
    }

    // Double hashing to handle collisions
    for (int j = 0; j < M; j++)
    {
        int k = input[j];
        int h1 = hash1(k, M);
        int h2 = hash2(k, R);
        int i = 0;

        while (hashTable[(h1 + h2 * i) % M] != -1) 
        {
            i++;
            if (i == M)
            {
                printf("No more elements can be inserted - Hash table is full\n");
                return;
            }
        }

        hashTable[(h1 + h2 * i) % M] = k;
    }
}

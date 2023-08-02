// Harsh - DSA- Assignment 4


#include <stdio.h>
#include <stdlib.h>

// Function prototype for hashInit
void hashInit(int* hashTable, int* input, int M, int R);

int main() 
{
    int input[] = { 764, 35954, 8683, 41, 11004, 1362, 77, 1, 448, 118, 5507 };
    int M = 11;
    int R = 7;
    int length = sizeof(input) / sizeof(input[0]);

    // Dynamically allocate memory for the hash table
    int* hashTable = (int*)malloc(M * sizeof(int));

    if (!hashTable) 
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Call the hashInit function to fill the hash table with the input array values
    hashInit(hashTable, input, M, R);

    // Print the contents of the hash table
    printf("Contents of hash table = \n");
    for (int i = 0; i < M; i++)
    {
        printf("hashTable[%d] = %d\n", i, hashTable[i]);
    }

    // Free dynamically allocated memory for the hash table
    free(hashTable);

    return 0;
}

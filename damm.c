// damm.c

// To calculate IDs and verify them

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

static int seed = 0;

const int damm_matrix[10][10] = {
    {0, 3, 1, 7, 5, 9, 8, 6, 4, 2},
    {7, 0, 9, 2, 1, 5, 4, 8, 6, 3},
    {4, 2, 0, 6, 8, 7, 1, 3, 5, 9},
    {1, 7, 5, 0, 9, 8, 3, 4, 2, 6},
    {6, 1, 2, 3, 0, 4, 5, 9, 7, 8},
    {3, 6, 7, 4, 2, 0, 9, 5, 8, 1},
    {5, 8, 6, 9, 7, 2, 0, 1, 3, 4},
    {8, 9, 4, 5, 3, 6, 2, 0, 1, 7},
    {9, 4, 3, 8, 6, 1, 7, 2, 0, 5},
    {2, 5, 8, 1, 4, 3, 6, 7, 9, 0},
};

void random_id(char* id, int length) {
    srand(time(NULL) + seed);
    seed++;

    for (int i = 0; i < length - 1; i++) {
        int random = rand();
        random %= 10;

        id[i] = 48 + random;
    }
}

int generate_damm_id(char* id, int length) {

    random_id(id, length);
    
    int row = 0;

    for (int i = 0; i < length - 1; i++) {

        int value = id[i] - 48;

        if (value < 0 || value > 9) {
            return 1;
        }

        row = damm_matrix[row][value];
    }

    id[length - 1] = row + 48;
    id[length] = 0;

    return 0;
}

int verify_damm_id(char* id, int length) {
    
    int row = 0;

    for (int i = 0; i < length; i++) {
        int value = id[i] - 48;

        if (value < 0 || value > 9) {
            return 1;
        }

        row = damm_matrix[row][value];
    }

    return row;
}
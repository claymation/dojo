#include <stdio.h>
#include <stdlib.h>

int** my2DAlloc(size_t rows, size_t cols)
{
    int** array = malloc(rows * cols * sizeof(int) + rows * sizeof(int*));
    if (!array) return array;
    int* cells = (int*)(array + rows);
    for (size_t i = 0; i != rows; ++i) {
        array[i] = cells + i * cols;
    }
    return array;
}

void fill(int** array, size_t rows, size_t cols, int x)
{
    if (!array) return;
    for (size_t i = 0; i != rows; ++i) {
        for (size_t j = 0; j != cols; ++j) {
            array[i][j] = x;
        }
    }
}

void zero(int** array, size_t rows, size_t cols)
{
    fill(array, rows, cols, 0);
}

void dump(int** array, size_t rows, size_t cols)
{
    if (!array) return;
    for (size_t i = 0; i != rows; ++i) {
        for (size_t j = 0; j != cols; ++j) {
            printf("%02d ", array[i][j]);
        }
        printf("\n");
    }
}

int main(int argc, char *argv[])
{
    const size_t rows = 5;
    const size_t cols = 5;

    int** array = my2DAlloc(rows, cols);

    zero(array, rows, cols);
    fill(array, rows, cols, 42);
    dump(array, rows, cols);

    return 0;
}

// Name: Jonathan Stock
// Date: Wednesday
// Title: Lab4 - Step3
// Description: This program computes matrix multiplication after initializing 2 matrixes then copying the first matrix into the second matrix. Then it doubles the first matrix and prints the result.

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

#define SIZE 1024

void *matrixMultiply(void *arg);
void *matrixCopy(void *arg);

pthread_t threads[SIZE];

double matrixA[SIZE][SIZE];
double matrixB[SIZE][SIZE];
double matrixC[SIZE][SIZE];

int main()
{
    int x = 0;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            matrixA[i][j] = x++;
            printf("%f ", matrixA[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            matrixB[i][j] = 0;
            printf("%f ", matrixB[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    static int i;
    static int j;

    pthread_create(&threads[0], NULL, matrixCopy, NULL);

    pthread_join(threads[0], NULL);

    pthread_create(&threads[1], NULL, matrixMultiply, NULL);

    pthread_join(threads[1], NULL);

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            printf("%f ", matrixC[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void *matrixCopy(void *arg)
{
    for (int a = 0; a < SIZE; a++)
    {
        for (int b = 0; b < SIZE; b++)
        {
            matrixB[a][b] = matrixA[a][b];
        }
    }
}

void *matrixMultiply(void *arg)
{
    for (int m = 0; m < SIZE; m++)
    {
        for (int n = 0; n < SIZE; n++)
        {
            matrixC[m][n] = matrixA[m][n] * 2;
        }
    }
}
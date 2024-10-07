//
// Created by batman on 8/29/24.
//

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 4

typedef struct
{
    int row;
    unsigned int n;
    unsigned int** arr1;
    unsigned int** arr2;
    unsigned int** ans;
} ThreadData;


void* multiplyRow(void* arg)
{
    const ThreadData* data = (ThreadData*)arg;
    const int row = data->row;
    const unsigned int n = data->n;

    for (unsigned int c = 0; c < n; ++c)
    {
        unsigned long long int sum = 0;
        for (unsigned int i = 0; i < n; ++i)
        {
            sum += (unsigned long long int)data->arr1[row][i] * data->arr2[i][c];
        }
        data->ans[row][c] = sum;
    }

    pthread_exit(0);
}

int main()
{
    unsigned int n;
    printf("Enter the value for n: ");
    scanf("%u", &n);

    unsigned int** arr1 = malloc(n * sizeof(unsigned int*));
    unsigned int** arr2 = malloc(n * sizeof(unsigned int*));
    unsigned int** ans = malloc(n * sizeof(unsigned int*));

    for (unsigned int i = 0; i < n; ++i)
    {
        arr1[i] = malloc(n * sizeof(unsigned int));
        arr2[i] = malloc(n * sizeof(unsigned int));
        ans[i] = malloc(n * sizeof(unsigned int));
    }

    for (unsigned int i = 0; i < n; ++i)
    {
        for (unsigned int j = 0; j < n; ++j)
        {
            arr1[i][j] = rand() % 100;
            arr2[i][j] = rand() % 100;
        }
    }

    printf("Assigned Random Values to Matrix A\n");
    printf("Assigned Random Values to Matrix B\n");

    printf("Calculating Matrix Multiplication: AxB\n");

    clock_t t = clock();

    pthread_t threads[MAX_THREADS];
    ThreadData thread_data[MAX_THREADS];

    for (unsigned int i = 0; i < n; ++i)
    {
        thread_data[i % MAX_THREADS] = (ThreadData){.row = i, .n = n, .arr1 = arr1, .arr2 = arr2, .ans = ans};
        pthread_create(&threads[i % MAX_THREADS], NULL, multiplyRow, &thread_data[i % MAX_THREADS]);

        if (i % MAX_THREADS == MAX_THREADS - 1 || i == n - 1)
        {
            for (unsigned int j = 0; j < MAX_THREADS && j <= i; ++j)
            {
                pthread_join(threads[j], NULL);
            }
        }
    }

    t = clock() - t;
    const double time_taken = (double)t / CLOCKS_PER_SEC; // in seconds

    printf("matrix multiplication took %f seconds to execute \n", time_taken);

    for (unsigned int i = 0; i < n; ++i)
    {
        free(arr1[i]);
        free(arr2[i]);
        free(ans[i]);
    }
    free(arr1);
    free(arr2);
    free(ans);

    return 0;
}

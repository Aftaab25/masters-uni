#include<stdio.h>
#include<time.h>
#include<stdlib.h>

double execTime(){
	
    
}

unsigned int getRandNo(unsigned int lower, unsigned int upper) {

	unsigned int num = (rand() % (upper - lower + 1)) + lower; 

    return num;
}


/*

// Allocate memory for matrices on the heap
    unsigned int **arr1 = (unsigned int **)malloc(n * sizeof(unsigned int *));
    unsigned int **arr2 = (unsigned int **)malloc(n * sizeof(unsigned int *));
    unsigned int **ans = (unsigned int **)malloc(n * sizeof(unsigned int *));
    
    for (unsigned int i = 0; i < n; ++i) {
        arr1[i] = (unsigned int *)malloc(n * sizeof(unsigned int));
        arr2[i] = (unsigned int *)malloc(n * sizeof(unsigned int));
        ans[i] = (unsigned int *)malloc(n * sizeof(unsigned int));
    }

    // Check for successful allocation
    if (arr1 == NULL || arr2 == NULL || ans == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

*/

int main(){
	unsigned int n;
	printf("Enter the value for n: ");
	scanf("%d", &n);

	// unsigned int arr1[n][n];
	// unsigned int arr2[n][n]; 
	// unsigned int ans[n][n];

	// Allocate memory for matrices on the heap
    unsigned long long int **arr1 = (unsigned long long int **)malloc(n * sizeof(unsigned long long int *));
    unsigned long long int **arr2 = (unsigned long long int **)malloc(n * sizeof(unsigned long long int *));
    unsigned long long int **ans = (unsigned long long int **)malloc(n * sizeof(unsigned long long int *));
    
    for (unsigned int i = 0; i < n; ++i) {
        arr1[i] = (unsigned long long int *)malloc(n * sizeof(unsigned long long int));
        arr2[i] = (unsigned long long int *)malloc(n * sizeof(unsigned long long int));
        ans[i] = (unsigned long long int *)malloc(n * sizeof(unsigned long long int));
    }

    // Check for successful allocation
    if (arr1 == NULL || arr2 == NULL || ans == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

	for (unsigned int i=0; i<n; ++i) {
		for (unsigned int j=0; j<n; ++j) {
			arr1[i][j] = getRandNo(1, 10000);
			arr2[i][j] = getRandNo(1, 10000);
		}
	}

	printf("============\n");

	for (unsigned int i=0; i<n; ++i) {
		for (unsigned int j=0; j<n; ++j) {
			printf("%d ", arr1[i][j]);
		}
		printf("\n");
	}

	printf("============\n");

	for (unsigned int i=0; i<n; ++i) {
		for (unsigned int j=0; j<n; ++j) {
			printf("%d ", arr2[i][j]);
		}
		printf("\n");
	}
	printf("============\n");

	clock_t t; 
    t = clock();

	for (unsigned int r=0; r<n; ++r) {
		for (unsigned int c=0; c<n; ++c) {
			unsigned int sum = 0;
			for (unsigned int i=0; i<n; ++i) {
				sum += arr1[r][i]*arr2[i][c];
			}
			ans[r][c] = sum;
		}
	}

	t = clock() - t; 
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds 
 
	printf("============\n");


	for (unsigned int i=0; i<n; ++i) {
		for (unsigned int j=0; j<n; ++j) {
			printf("%d ", ans[i][j]);
		}
		printf("\n");
	}
	printf("============\n");

	printf("matrix multiplication took %f seconds to execute \n", time_taken); 

	return 0;
}
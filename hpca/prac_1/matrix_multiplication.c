//
// Created by batman on 8/29/24.
//

#include<stdio.h>
#include<time.h>
#include<stdlib.h>

unsigned int getRandNo(const unsigned int lower, const unsigned int upper) {
	const unsigned int num = rand() % (upper - lower + 1) + lower;
    return num;
}

int main(){
	unsigned int n;
	printf("Enter the value for n: ");
	scanf("%d", &n);

	if (n == 0) {
		printf("The number is 0\n");
		return 1;
	}

	// Allocate memory for matrices on the heap
    unsigned long long int **arr1 = malloc(n * sizeof(unsigned long long int *));
    unsigned long long int **arr2 = malloc(n * sizeof(unsigned long long int *));
    unsigned long long int **ans = malloc(n * sizeof(unsigned long long int *));

	if (arr1 == NULL || arr2 == NULL || ans == NULL) {
		printf("Memory allocation failed\n");
		free(arr1);
		free(arr2);
		free(ans);
		return 1;
	}

    for (unsigned int i = 0; i < n; ++i) {
        arr1[i] = (unsigned long long int *)malloc(n * sizeof(unsigned long long int));
        arr2[i] = (unsigned long long int *)malloc(n * sizeof(unsigned long long int));
        ans[i] = (unsigned long long int *)malloc(n * sizeof(unsigned long long int));
	    // Check for successful allocation
	    if (arr1[i] == NULL || arr2[i] == NULL || ans[i] == NULL) {
	        printf("Memory allocation failed.\n");

	    	// Free previously allocated rows
	    	for (int j = 0; j < i; j++) {
	    		free(arr1[j]);
	    		free(arr2[j]);
	    		free(ans[j]);
	    	}

	    	// Free the arrays of pointers
	    	free(arr1);
	    	free(arr2);
	    	free(ans);

	    	return 1;
	    }
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
			printf("%llu ", arr1[i][j]);
		}
		printf("\n");
	}

	printf("============\n");

	for (unsigned int i=0; i<n; ++i) {
		for (unsigned int j=0; j<n; ++j) {
			printf("%llu ", arr2[i][j]);
		}
		printf("\n");
	}
	printf("============\n");

	clock_t t;
    t = clock();

	for (unsigned int r=0; r<n; ++r) {
		for (unsigned int c=0; c<n; ++c) {
			unsigned long long int sum = 0;
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
			printf("%llu ", ans[i][j]);
		}
		printf("\n");
	}
	printf("============\n");

	printf("matrix multiplication took %f seconds to execute \n", time_taken);

	// Freeing allocated memory
	for (int i = 0; i < n; i++) {
		free(arr1[i]);
		free(arr2[i]);
		free(ans[i]);
	}

	free(arr1);
	free(arr2);
	free(ans);

	return 0;
}
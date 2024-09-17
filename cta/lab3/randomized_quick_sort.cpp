#include <bits/stdc++.h>
using namespace std;

#define nline "\n"

int partition(vector<int>& arr, int low, int high, const string& pivot_type) {
    int pivot_index;
    
    // Choose the pivot index based on the strategy
    if (pivot_type == "first") {
        pivot_index = low;
    } else if (pivot_type == "last") {
        pivot_index = high;
    } else if (pivot_type == "random") {
        pivot_index = low + rand() % (high - low + 1);
    } else if (pivot_type == "middle") {
        pivot_index = low + (high - low) / 2;
    }
    
    // Swap pivot with the low
    int pivot = arr[pivot_index];
    swap(arr[pivot_index], arr[low]);
    
    int i = low + 1;
    int j = high;

    while (i <= j) {
        while (i <= high && arr[i] <= pivot) {
            i++;
        }

        while (j > low && arr[j] > pivot) {
            j--;
        }

        if (i < j) {
            swap(arr[i], arr[j]);
        }
    }

    // Place the pivot in its correct position
    swap(arr[low], arr[j]);
    return j;
}

// Quick Sort function
void quickSort(vector<int> &arr, int low, int high, string pivot_type) {
    if (low < high) {
        int pi = partition(arr, low, high, pivot_type);
        quickSort(arr, low, pi - 1, pivot_type);
        quickSort(arr, pi + 1, high, pivot_type);
    }
}

// Function to generate test data (ascending, descending, random)
vector<int> generateTestData(int size, string order_type) {
    vector<int> data(size);
    if (order_type == "ascending") {
        for (int i = 0; i < size; i++) {
            data[i] = i + 1;
        }
    } else if (order_type == "descending") {
        for (int i = 0; i < size; i++) {
            data[i] = size - i;
        }
    } else if (order_type == "random") {
        for (int i = 0; i < size; i++) {
            data[i] = rand() % size;
        }
    }
    return data;
}

// Function to measure execution time
double measureExecutionTime(vector<int> &arr, string pivot_type) {
    auto start = chrono::high_resolution_clock::now();
    quickSort(arr, 0, arr.size() - 1, pivot_type);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> diff = end - start;
    return diff.count();
}

int main() {
    // Sizes of input data
    vector<int> sizes = {10000, 50000, 100000};

    // Order types for the input data
    vector<string> order_types = {"ascending", "descending", "random"};

    // Pivot selection strategies
    vector<string> pivot_types = {"first", "last", "random", "middle"};

    // Measure time for each combination of input type, size, and pivot strategy
    for (const int &size : sizes) {
        for (const string &order_type : order_types) {
            vector<int> data = generateTestData(size, order_type);
            cout << "Input Size: " << size << ", Order: " << order_type << nline;

            for (const string &pivot_type : pivot_types) {
                vector<int> temp_data = data; // Copy original data for each sort
                double time_taken = measureExecutionTime(temp_data, pivot_type);
                cout << "  Pivot: " << pivot_type << " -> Time Taken: " << time_taken << " seconds" << nline;
            }
            cout << nline;
        }
    }

    return 0;
}

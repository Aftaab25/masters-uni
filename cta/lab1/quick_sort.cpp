#include<bits/stdc++.h>
#include "matplotlibcpp.h"

using namespace std;
namespace plt = matplotlibcpp;

/*
 * CONSTANTS
 * */
#define ASC 1
#define DESC 2
#define RANDOM 3
#define nline "\n";

void printArr(vector<int> v) {
    for (int i: v) {
        cout << i << " ";
    }
    cout << nline;
}

int getRandNo(int min, int max) {
    // --------------- Random Number Generator -------------------------- //
    random_device rd; 
    mt19937 gen(rd()); 

    uniform_int_distribution<> dist(min, max);

    return dist(gen);
}

vector<vector<int>> getRandomNumberArr(int min, int max) {
    vector<vector<int>> res;
    // Asc Order
    vector<int> asc;
    for (int i=min; i<=max; ++i) {
        asc.push_back(i);
    }

    // Desc Order
    vector<int> desc;
    for (int i=max; i>=min; --i) {
        desc.push_back(i);
    }

    // Random
    vector<int> random;
    for(int i=min; i<=max; ++i) {
        random.push_back(getRandNo(min, max));
    }

    res.push_back(asc);
    res.push_back(desc);
    res.push_back(random);

    return res;
} 

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[low];
    int i = low;
    int j = high;

    while (i<j) {
        while (arr[i] <= pivot && i <= high - 1) {
            i++;
        }
    
        while (arr[j] > pivot && j > low) {
            j--;
        }
    
        if (i < j) {
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[low], arr[j]);
    return j;
}

void quick_sort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivotIdx = partition(arr, low, high);
        quick_sort(arr, low, pivotIdx - 1);
        quick_sort(arr, pivotIdx + 1, high);
    }
}


int main() {
    
    int min = 1;

    vector<int> input_ranges = {10000, 50000, 100000};

    vector<double> asc_times;
    vector<double> desc_times;
    vector<double> random_times;

    for (int i=0; i<3; ++i) {
        vector<vector<int>> inputArrays = getRandomNumberArr(min, input_ranges[i]);
        int orderCount = 0;
        // For each range -> 3 vectors
        for (vector<int> array: inputArrays) {
            orderCount++;
            auto start = chrono::high_resolution_clock::now();
            quick_sort(array, 0, array.size()-1);
            auto end = chrono::high_resolution_clock::now();

            chrono::duration<double> duration = end - start;

            switch(orderCount) {
                case ASC:
                    asc_times.push_back(duration.count());
                    break;
                case DESC:
                    desc_times.push_back(duration.count());
                    break;
                case RANDOM:
                    random_times.push_back(duration.count());
                    break;
            }
                    
            cout << "Execution time: for range: " << i << " and " << duration.count() << " seconds" << endl;

        }
        cout << "-------------------------------" << nline;
    }

    // TODO: Need to plot the data
    plt::named_plot("Ascending Data", input_ranges, asc_times, "r-o");
    plt::named_plot("Descending Data", input_ranges, desc_times, "g-o");
    plt::named_plot("Random Data", input_ranges, random_times, "b-o");

    // Add labels and title
    plt::xlabel("Input Range");
    plt::ylabel("Time (s)");
    plt::title("Bubble Sort Performance");
    plt::legend();

    // Show the plot
    plt::show();

}


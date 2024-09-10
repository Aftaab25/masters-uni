#include<bits/stdc++.h>
using namespace std;

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

// Bubble sort
void bubble_sort(vector<int>& arr) {
    for (int i=0; i<arr.size()-1; i++){
        for (int j=arr.size()-1; j>=i; j--) {
            if (arr[j-1] > arr[j]) swap(arr[j-1], arr[j]);
        }
    }
}

// Selection Sort
void selection_sort(vector<int>& arr) {
    int min_;
    for (int i=0; i<arr.size()-1; i++){
        min_ = i;
        for (int j=i+1; j<arr.size(); j++) {
            if (arr[j] < arr[min_]) {
                min_ = j;
            }
        }
        if (min_ != i) {
            swap(arr[i], arr[min_]);
        }
    }
}

// Insertion Sort
void insertion_sort(vector<int>& arr) {
    for (int i=1; i<arr.size(); i++){
        int x = i-1;
        int key = arr[i];
        while(x>=0 && arr[x] > key) {
            arr[x+1] = arr[x];
            x--;
        }
        arr[x+1] = key;
    }
}

// Partitioning for Quick Sort
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[low];
    int i = low;
    int j = high;

    while (i<j) {
        while (i <= high && arr[i] <= pivot) {
            i++;
        }
    
        while (arr[j] > pivot) {
            j--;
        }
    
        if (i < j) {
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[low], arr[j]);
    return j;
}

// Quick Sort
void quick_sort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivotIdx = partition(arr, low, high);
        quick_sort(arr, low, pivotIdx - 1);
        quick_sort(arr, pivotIdx + 1, high);
    }
}

void displayMenu() {
    cout << "Choose a sorting algorithm:" << endl;
    cout << "1. Bubble Sort" << endl;
    cout << "2. Insertion Sort" << endl;
    cout << "3. Selection Sort" << endl;
    cout << "4. Quick Sort" << endl;
}

int getUserChoice() {
    int choice;
    while (true) {
        cout << "Enter the number corresponding to your choice (1-4): ";
        cin >> choice;

        // Check if the input is an integer and within the valid range
        if (cin.fail() || choice < 1 || choice > 4) {
            cin.clear(); // Clear the error flag
            cin.ignore(10000, '\n'); // Discard invalid input
            cout << "Invalid choice. Please enter a number between 1 and 4." << endl;
        } else {
            break; // Valid choice, break the loop
        }
    }
    return choice;
}

int main() {
    
    displayMenu();
    int userChoice = getUserChoice();

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
            switch (userChoice) {
                case 1:
                    bubble_sort(array);
                    break;
                case 2:
                    insertion_sort(array);
                    break;
                case 3:
                    selection_sort(array);
                    break;
                case 4:
                    quick_sort(array, 0, array.size()-1);
                    break;
                default:
                    cout << "Error." << endl;
                    break;
            }
            auto end = chrono::high_resolution_clock::now();

            chrono::duration<double> duration = end - start;

            string order_type;
            switch(orderCount) {
                case ASC:
                    asc_times.push_back(duration.count());
                    order_type = "Ascending Data";
                    break;
                case DESC:
                    desc_times.push_back(duration.count());
                    order_type = "Descending Data";
                    break;
                case RANDOM:
                    random_times.push_back(duration.count());
                    order_type = "Random Ordered Data";
                    break;
            }
                    
            cout << "Execution time: for " << order_type << " : " << duration.count() << " seconds" << endl;

        }
        cout << "-------------------------------" << nline;
    }

}


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

void merge(vector<int>& arr, int low,int mid , int high) {
    vector<int> temp;
    int l = low;
    int r = mid+1;

    while (l <= mid && r <= high) {
        if (arr[l] <= arr[r]) {
            temp.emplace_back(arr[l]);
            l++;
        }
        else {
            temp.emplace_back(arr[r]);
            r++;
        }
    }

    // if left is stell left
    while(l <= mid) {
        temp.emplace_back(arr[l]);
        l++;
    }
    
    // if right is still left
    while(r <= high) {
        temp.emplace_back(arr[r]);
        r++;
    }
    
    for (int i=low; i<=high; i++) {
        arr[i] = temp[i-low];
    }

}


/*
 * Merge Sort Logic:
 * if low >= high: return
 * Find the mid-point using low and high
 * merge each sorted half of the array using merge()
*/
void merge_sort(vector<int>& arr, int low, int high) {
    if (low >= high) {
        return;
    }
    int mid = (low + high) / 2;
    merge_sort(arr, low, mid);
    merge_sort(arr, mid+1, high);

    merge(arr, low, mid, high);
}


void displayMenu() {
    cout << "Choose a sorting algorithm:" << endl;
    cout << "1. Merge Sort" << endl;
    cout << "2. External Merge Sort" << endl;
}

int getUserChoice() {
    int choice;
    while (true) {
        cout << "Enter the number corresponding to your choice (1-2): ";
        cin >> choice;

        // Check if the input is an integer and within the valid range
        if (cin.fail() || choice < 1 || choice > 2) {
            cin.clear(); // Clear the error flag
            cin.ignore(10000, '\n'); // Discard invalid input
            cout << "Invalid choice. Please enter a number between 1 and 2." << endl;
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
                    merge_sort(array, 0, array.size()-1);
                    break;
                case 2:
                    merge_sort_external(array, 0, array.size()-1);
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
                    
            cout << "Execution time for " << order_type << " (array size " << array.size() << ") : " << duration.count() << " seconds" << endl;

        }
        cout << "-------------------------------" << nline;
    }

}


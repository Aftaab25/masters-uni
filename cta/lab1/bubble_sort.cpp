#include<bits/stdc++.h>
using namespace std;

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

void bubble_sort(vector<int>& arr) {
    for (int i=0; i<arr.size()-1; i++){
        for (int j=arr.size()-1; j>=i; j--) {
            if (arr[i] > arr[j]) swap(arr[i], arr[j]);
        }
    }
}

int main() {
    
    int min = 1;
    vector<int> maxes = {10000, 50000, 100000};
    // int max1 = 10000;
    // int max2 = 50000;
    // int max3 = 100000;

    for (int i=0; i<3; ++i) {
        vector<vector<int>> res = getRandomNumberArr(min, maxes[i]);
        // For each range -> 3 vectors
        for (vector<int> v: res) {

            auto start = chrono::high_resolution_clock::now();
            bubble_sort(v);
            auto end = chrono::high_resolution_clock::now();

            chrono::duration<double> duration = end - start;
            cout << "Execution time: for range: " << i << " and " << duration.count() << " seconds" << endl;
        }
        cout << "-------------------------------" << nline;
    }

    // vector<int> arr = {2, 3, 1, 3, 5};
    // bubble_sort(arr);
    // printArr(arr);

}


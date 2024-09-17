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

vector<int> merge_k_sorted_vectors(const vector<int>& vector1, const vector<int>& vector2) {
    
    // check if any vector is empty, return the other vector
    if (vector1.size() == 0) {
        return vector2;
    }
    if (vector2.size() == 0) {
        return vector1;
    }

    vector<int> result_vector;
    int l = 0, r = 0;
    while (l < vector1.size() && r < vector2.size()) {
        if (vector1[l] <= vector2[r]) {
            result_vector.push_back(vector1[l++]);
        }
        else {
            result_vector.push_back(vector2[r++]);
        }
    }

    while (l < vector1.size()) {
        result_vector.push_back(vector1[l++]);
    }

    while (r < vector2.size()) {
        result_vector.push_back(vector2[r++]);
    }

    return result_vector;

}

void external_merge_k_sorted_files(const vector<string>& chunk_files, const string& output_file) {
    vector<ifstream> files(chunk_files.size());
    vector<int> current_vals(chunk_files.size(), numeric_limits<int>::max());
    vector<bool> file_exhausted(chunk_files.size(), false);  // To track if the file is completely read

    // Open each chunk file and initialize the first values
    for (int i = 0; i < chunk_files.size(); ++i) {
        files[i].open(chunk_files[i]);
        if (files[i] >> current_vals[i]) {
            // Successfully read the first element from each file
        } else {
            file_exhausted[i] = true;  // Mark file as exhausted if empty
        }
    }

    ofstream outfile(output_file);

    // Merge process until all files are exhausted
    while (true) {
        int min_value = numeric_limits<int>::max();
        int min_index = -1;

        // Find the smallest current value
        for (int i = 0; i < current_vals.size(); ++i) {
            if (!file_exhausted[i] && current_vals[i] < min_value) {
                min_value = current_vals[i];
                min_index = i;
            }
        }

        // If all files are exhausted, break
        if (min_index == -1) {
            break;
        }

        // Write the smallest element to the output file
        outfile << min_value << " ";

        // Advance the pointer for the file that had the smallest element
        if (files[min_index] >> current_vals[min_index]) {
            // Successfully read the next element
        } else {
            file_exhausted[min_index] = true;  // Mark this file as exhausted if no more elements
        }
    }

    // Close all files
    for (int i = 0; i < chunk_files.size(); ++i) {
        files[i].close();
    }

    outfile.close();
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

void write_chunk_to_file(const string& filename, const vector<int>& chunk) {
    ofstream outfile(filename);
    for (const int& value : chunk) {
        outfile << value << endl;
    }
    outfile.close();
}

// Function to read data from a file and return it as a vector of integers
vector<int> read_file(const string& filename) {
    vector<int> data;
    ifstream infile(filename);
    int value;

    while (infile >> value) {  // Read the file line by line
        data.push_back(value);
    }

    infile.close();
    return data;
}

int external_merge_sort(vector<int>& arr, int chunk_size, int size_of_array, int orderType) {

    /*
     * orderType: 1 => Ascending Order
     * orderType: 2 => Descending Order
     * orderType: 3 => Random Order
     * */

    string order_type;
    switch(orderType) {
        case ASC:
            order_type = "ascending";
            break;
        case DESC:
            order_type = "descending";
            break;
        case RANDOM:
            order_type = "random";
            break;
    }

    // int chunk_size = arr.size() / no_of_chunks;
    int no_of_chunks = ceil((double) arr.size() / chunk_size);
    if (no_of_chunks > chunk_size) {
        cout << "No. of chunks created is greater than the chunk size, hence External Merge Sort not possible!" << nline;
        return 0;
    }

    // Split the array into chunks and write to files
    for (int i = 0; i < no_of_chunks; i++) {
        vector<int> chunk(arr.begin() + i * chunk_size, arr.begin() + (i + 1) * chunk_size);
        string filename = "chunks/" + to_string(size_of_array) + "_" + order_type + "_chunk_" + to_string(i + 1) + ".txt";
        write_chunk_to_file(filename, chunk);
    }

    // Read the data from these chunks 
    // sort them 
    // write it back
    for (int i = 0; i < no_of_chunks; i++) {
        string filename = "chunks/" + to_string(size_of_array) + "_" + order_type + "_chunk_" + to_string(i + 1) + ".txt";
        // string filename = "chunks/chunk_" + to_string(i + 1) + "_" + to_string(size_of_array) + ".txt";

        // Read data from the file
        vector<int> data = read_file(filename);

        // Sort the data
        // sort(data.begin(), data.end());
        merge_sort(data, 0, data.size()-1);

        write_chunk_to_file(filename, data);
    }

    // Merge them files.
    vector<string> chunk_files;
    for (int i=0; i < no_of_chunks; ++i) {
        string filename = "chunks/" + to_string(size_of_array) + "_" + order_type + "_chunk_" + to_string(i + 1) + ".txt";
        chunk_files.push_back(filename);
    }

    // Output merged result to a file
    string output_file_name = "chunks/output_" + to_string(size_of_array) + "_" + order_type + ".txt";
    external_merge_k_sorted_files(chunk_files, output_file_name);

    return 1;
}

int main() {
    
    int chunk_size;
    int min = 1;

    cout << "Maximum number elements in a memory chunk: ";
    cin >> chunk_size;

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
            external_merge_sort(array, chunk_size, array.size(), orderCount);
            auto end = chrono::high_resolution_clock::now();
            // if (check == 0) return 0;

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


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

int solve(set<int> denominationsSet, int& totalAmount, unordered_map<int, int>& result) {

    for (const int value: denominationsSet) {
        int count = totalAmount/value;
        totalAmount = totalAmount % value;
        result[value] = count;
    }

    return totalAmount == 0;

}

int main() {

    int totalAmount;
    cout << "Enter the total Amount: ";
    cin >> totalAmount;

    if (totalAmount < 0) {
        cout << "No change is available for amount lesser than 0" << endl;
        return 0;
    }

    vector<int> denominations;
    unordered_map<int, int> result;

    cout << "Enter the denominations: " << nline;

    do {
        int x; cin >> x; 
        if (x < 0) {
            cout << "Negative Denomination is not possible!" << nline;
            return 0;
        }

        denominations.push_back(x);
    } while  ( cin.get() != '\n');

    set<int> denominationsSet(denominations.begin(), denominations.end());

    int valid = solve(denominationsSet, totalAmount, result);

    cout << "Denominations distributions: " << nline;
    for (const auto it: result) {
        cout << "Denomination " << it.first << " has count: " << it.second << nline;
    }

    if (!valid) {
        cout << "With a spare amount of: " << totalAmount << nline;
    }

    return 0;

}


#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> arrayRankTransform(vector<int>& arr) {
    // Step 1: Create a sorted set of unique elements
    vector<int> unique_sorted = arr; // Copy the original array
    sort(unique_sorted.begin(), unique_sorted.end());
    unique_sorted.erase(unique(unique_sorted.begin(), unique_sorted.end()), unique_sorted.end());

    // Step 2: Create a rank map
    unordered_map<int, int> rank_map;
    for (int i = 0; i < unique_sorted.size(); ++i) {
        rank_map[unique_sorted[i]] = i + 1; // Rank is 1-based
    }

    // Step 3: Replace elements in arr with their ranks
    vector<int> result(arr.size());
    for (int i = 0; i < arr.size(); ++i) {
        result[i] = rank_map[arr[i]];
    }

    return result;
}

int main() {
    vector<int> arr = {40, 10, 20, 30};
    vector<int> rankedArray = arrayRankTransform(arr);

    // Print the result
    for (int rank : rankedArray) {
        cout << rank << " ";
    }
    cout << endl; // Output: 4 1 2 3

    return 0;
}

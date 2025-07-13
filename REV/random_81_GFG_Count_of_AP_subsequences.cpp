#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int count(vector<int>& arr) {
        int n = arr.size();
        if(!n) return 0;

        int total = 1+n;
        vector<unordered_map<int, int>> dp(n);
        for(int i = 1; i<n; i++){
            for(int j = 0; j<i; j++){
                int d = arr[i]-arr[j];

                int count = 1+dp[j][d];
                dp[i][d] += count;
                total+=count;
            }
        }
        return total;class Solution {
  public:
    int lengthOfLongestAP(vector<int>& arr) {
        // code here
    }
};
    }
// private:
//     int n;
//     unordered_map<string, int> mp; // Memoization table

//     int solve(int ind, int cd, const vector<int>& arr) {
//         if (ind == n) {
//             return 1; 
//         }

//         string key = to_string(ind) + "," + to_string(cd);
//         if (mp.find(key) != mp.end()) {
//             return mp[key];
//         }

//         int result = 1;
//         for (int i = ind + 1; i < n; ++i) {
//             int d = arr[i] - arr[ind];

//             if (cd == -1 || d == cd) {
//                 result += solve(i, d, arr); 
//             }
//         }

//         result += solve(ind + 1, cd, arr);

//         return mp[key] = result;
//     }

// public:
//     int count(vector<int>& arr) {
//         n = arr.size();
//         return solve(0, -1, arr);
//     }
};

int main(){
    string str;
    getline(cin, str);
    stringstream ss(str);

    vector<int> arr;
    int num;
    while(ss>>num)
        arr.push_back(num);
    
    Solution obj;
    cout<<obj.count(arr);

    return 0;
}
















// #include <iostream>
// #include <vector>
// #include <unordered_map>
// using namespace std;

// class Solution {
// private:
//     int n; // Size of the array
//     unordered_map<string, int> memo; // Memoization table

//     // Recursive function to count AP subsequences
//     int solve(int ind, int cd, const vector<int>& arr) {
//         // Base case: If we've reached the end of the array
//         if (ind == n) {
//             return 1; // Every subsequence ends here (including the empty subsequence)
//         }

//         // Create a unique key for memoization
//         string key = to_string(ind) + "," + to_string(cd);
//         if (memo.find(key) != memo.end()) {
//             return memo[key]; // Return cached result if available
//         }

//         int result = 0;

//         // Include subsequences starting from the current index
//         for (int i = ind + 1; i < n; ++i) {
//             int d = arr[i] - arr[ind]; // Calculate the difference

//             // If the common difference matches or hasn't been set yet
//             if (cd == -1 || d == cd) {
//                 result += solve(i, d, arr); // Recurse with updated common difference
//             }
//         }

//         // Add the subsequence that excludes the current element
//         result += solve(ind + 1, cd, arr);

//         // Store the result in the memoization table
//         return memo[key] = result;
//     }

// public:
//     // Public function to initiate the counting process
//     int count(vector<int>& arr) {
//         n = arr.size(); // Set the size of the array
//         return solve(0, -1, arr); // Start from index 0 with no common difference (-1)
//     }
// };

// int main() {
//     // Input array
//     vector<int> arr = {1, 2, 3};

//     // Create an instance of the Solution class
//     Solution solution;

//     // Call the count function and print the result
//     cout << "Total AP subsequences: " << solution.count(arr) << endl;

//     return 0;
// }
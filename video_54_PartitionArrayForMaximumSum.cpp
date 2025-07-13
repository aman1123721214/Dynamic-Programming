// #include<iostream>
// #include<bits/stdc++.h>
// using namespace std;

/*************************************** MEMOIZATION **************************************************** */
// int solve(int i, int k, int n, vector<int> &arr, vector<int> &dp){
//     if(i == n) return 0;
//     if(dp[i] != -1) return dp[i];
//     int len = 0, maxAns = -1e9, maxi = -1e9;
//     for(int j = i; j<min(n, i+k); j++){
//         len++;
//         maxi = max(maxi, arr[j]);
//         int sum = len*maxi+solve(j+1, k, n, arr, dp);
//         maxAns = max(maxAns, sum);
//     }return dp[i] = maxAns;
// }
// int maximumSubarray(vector<int> &arr, int k){
//     // Write your code here.
//     int n = arr.size();
//     vector<int> dp(n, -1);
//     return solve(0, k, n, arr, dp);
// }


/************************************* TABULATION ****************************************************** */

// int maximumSubarray(vector<int> &arr, int k){
//     // Write your code here.
//     int n = arr.size();
//     vector<int> dp(n+1, 0);
//     dp[n] = 0;
//     int len = 0, maxAns = -1e9;
//     for(int i = n-1; i>=0; i--){
//         int len = 0, maxi = -1e9;
//         for(int j = i; j<min(n, i+k); j++){
//             len++;
//             maxi = max(maxi, arr[j]);
//             int sum = len*maxi+dp[j+1];
//             maxAns = max(maxAns, sum);
//         }dp[i] = maxAns;
//     }return dp[0];
// }

/*************************************** MAIN ********************************************************* */

// int main(){
//     int n, k;
//     cin>>n>>k;
//     vector<int> arr(n, 0);
//     for(int i = 0; i<n; i++) cin>>arr[i];
//     cout<<maximumSubarray(arr, k);
//     return 0;
// }
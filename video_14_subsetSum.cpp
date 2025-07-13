// #include<iostream>
// #include<bits/stdc++.h>
// using namespace std;
/*************************************************** MEMOIZATION ******************************************************* */
// bool solve(int ind, int target, vector<int> &arr, vector<vector<int>> &dp){
//     if(target == 0) return 1;
//     if(ind == 0) return (arr[0] == target);
//     if(dp[ind][target] != -1) return dp[ind][target];

//     bool notTake = solve(ind-1, target, arr, dp);
//     bool take = 0;
//     if(arr[ind]<=target) 
//         take = solve(ind-1, target-arr[ind], arr, dp);
    
//     return dp[ind][target] = take || notTake;
// }
// bool subsetSumToK(int n, int k, vector<int> &arr) {
//     // Write your code here.
//     vector<vector<int>> dp(n, vector<int> (k+1, -1));
//     return solve(n-1, k, arr, dp);
// }

/*************************************************** TABULATION ******************************************************* */
// bool subsetSumToK(int n, int k, vector<int> &arr) {
//     // Write your code here.
//     vector<vector<bool>> dp(n, vector<bool> (k+1, 0));
//     for(int i = 0; i<n; i++) dp[i][0] = 1;
//     dp[0][arr[0]] = 1;

//     for(int ind = 1; ind<n; ind++){
//         for(int target = 1; target<=k; target++){
//             bool notTake = dp[ind-1][target];
//             bool take = 0; 
//             if(arr[ind]<=target)
//             take = dp[ind-1][target-arr[ind]];

//             dp[ind][target] = take||notTake; 
//         }
//     }
//     return dp[n-1][k];
// }

/*************************************************** MAX SPACE OPT *************************************************** */


/*************************************************** MAIN ************************************************************ */

// int main(){
//     int n, k;
//     cin>>n>>k;
//     vector<int> arr(n);
//     for(int i = 0; i<n; i++){
//         cin>>arr[i];
//     }
//     cout<<subsetSumToK(n, k, arr);
// }
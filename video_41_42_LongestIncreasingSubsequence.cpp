// #include<iostream>
// #include<bits/stdc++.h>
// using namespace std;

/***************************************** MEMOIZATION ************************************************** */
// int solve(int ind, int prev_ind, int *arr, int n, vector<vector<int>> &dp){
//     if(ind == n) return 0;
//     if(dp[ind][prev_ind+1] != -1) return dp[ind][prev_ind+1];

//     int len = solve(ind+1, prev_ind, arr, n, dp); //not take
//     if(prev_ind == -1 || arr[ind]>arr[prev_ind])
//     len = max(len, 1+solve(ind+1, ind, arr, n, dp)); //take
//     return dp[ind][prev_ind+1] = len;
// }
// int longestIncreasingSubsequence(int arr[], int n){
//     // Write Your Code here
//     vector<vector<int>> dp(n, vector<int> (n+1, -1));
//     return solve(0, -1, arr, n, dp);
// }

/**************************************** TABULATION *************************************************** */

// int longestIncreasingSubsequence(int arr[], int n){
//     // Write Your Code here
//     vector<vector<int>> dp(n+1, vector<int> (n+1, 0));
    
//     for(int ind = n-1; ind>=0; ind--){
//         for(int prev_ind = ind-1 ; prev_ind>=-1; prev_ind--){
//             int ntake = dp[ind+1][prev_ind+1];
//             int take = -1e9;
//             if(prev_ind == -1 || arr[ind]>arr[prev_ind])
//                 take = 1+dp[ind+1][ind+1];
//             dp[ind][prev_ind+1] = max(take, ntake);
//         }
//     }return dp[0][0];
// }

/****************************************** MAX SPACE OPT ******************************************** */
// int longestIncreasingSubsequence(int arr[], int n){
//     // Write Your Code here
//     vector<int> after(n+1, 0), curr(n+1, 0);
    
//     for(int ind = n-1; ind>=0; ind--){
//         for(int prev_ind = ind-1 ; prev_ind>=-1; prev_ind--){
//             int ntake = after[prev_ind+1];
//             int take = -1e9;
//             if(prev_ind == -1 || arr[ind]>arr[prev_ind])
//                 take = 1+after[ind+1];
//             curr[prev_ind+1] = max(take, ntake);
//         }
//         after = curr;
//     }return after[0];
// }

/******************************************* MOST EFFICIENT S.C = O(N) ***************************** */
//  int longestIncreasingSubsequence(int arr[], int n){
//     // Write Your Code here
//     vector<int> dp(n, 1);
//     int ans = -1e9;
//     for(int ind = 0; ind<n; ind++){
//         for(int prev_ind = 0 ; prev_ind<ind; prev_ind++){
//             if(arr[ind]>arr[prev_ind])
//                 dp[ind] = max(dp[ind], 1+dp[prev_ind]);
//         }
//         ans = max(ans, dp[ind]);
//     }return ans;
// }
// int main(){
//     int n; 
//     cin>>n;
//     int arr[n] = {0};
//     for(int i = 0; i<n; i++) cin>>arr[i];
//     cout<<longestIncreasingSubsequence(arr, n);
//     return 0;
// }

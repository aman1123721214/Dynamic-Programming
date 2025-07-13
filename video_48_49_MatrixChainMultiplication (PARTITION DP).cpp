#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/********************************************* PARTITION DP ********************************************** */

/********************************************* MEMOIZATION *********************************************** */
// int solve(int i, int j, vector<int> &arr, vector<vector<int>> &dp){
//     if(i == j) return 0;

//     if(dp[i][j] != -1) return dp[i][j];
//     int ans = 1e9;

//     for(int k = i; k<j; k++){
//         int steps = arr[i-1]*arr[k]*arr[j] + 
//         solve(i, k, arr, dp) + solve(k+1, j, arr, dp);
//         ans = min(ans, steps);
//     }
//     return dp[i][j] = ans;
// }
// int matrixMultiplication(vector<int> &arr, int N){
//     // Write your code here.
//     vector<vector<int>> dp(N, vector<int> (N, -1));
//     return solve(1, N-1, arr, dp);
// }

/********************************************* TABULATION ********************************************* */

// int matrixMultiplication(vector<int> &arr, int n){
//     // Write your code here.
//     vector<vector<int>> dp(n, vector<int> (n, 0));
//     //no need to specify base-case because the dp is already initailized with 0
//     int ans = 1e9;

//     //writing the memoization soln in opposite manner    
//     for(int i = n-1; i>=1; i--){
//         for(int j = i+1; j<n; j++){
//             int ans = 1e9;
//             for(int k = i; k<j; k++){
//                 int steps = arr[i-1]*arr[k]*arr[j] + 
//                 dp[i][k] + dp[k+1][j] ;
//                 ans = min(ans, steps);
//             }
//             dp[i][j] = ans;
//         }
//     }
//     return dp[1][n-1];    
// }

// int main(){
//     int n; cin>>n;
//     vector<int> arr(n, 0);
//     for(int i = 0; i<n; i++) cin>>arr[i];
//     cout<<matrixMultiplication(arr, n);
//     return 0;
// }
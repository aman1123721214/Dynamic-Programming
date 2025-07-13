// #include<iostream> 
// #include<bits/stdc++.h>
// using namespace std;

// Next video_52_EvaluateBooleanExpression_to_True is hard to understand so give extra time on it

/********************************************* MEMOIZATION ************************************************** */
// int solve(int i, int j, vector<int> &arr, vector<vector<int>> &dp){
//     if(i>j) return 0;
//     if(dp[i][j] != -1) return dp[i][j];
//     int maxi = INT_MIN;
//     for(int ind = i; ind<=j; ind++){
//         int cost = arr[i-1]*arr[ind]*arr[j+1]+
//         solve(i, ind-1, arr, dp)+solve(ind+1, j, arr, dp);
//         maxi = max(maxi, cost);
//     }return dp[i][j] = maxi;
// }
// int maxCoins(vector<int>& a){
// 	// Write your code here.
//     int n = a.size();
//     a.insert(a.begin(), 1);
//     a.push_back(1);
//     vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
//     return solve(1, n, a, dp);
// }

/********************************************** TABULATION *************************************************** */

// int maxCoins(vector<int>& arr){
// 	// Write your code here.
//     int n = arr.size();
//     arr.insert(arr.begin(), 1);
//     arr.push_back(1);
//     vector<vector<int>> dp(n+2, vector<int> (n+2, 0));
//     for(int i = n; i>=1; i--){
//         for(int j = 1; j<=n; j++){
//             if(i>j) continue;
//             int maxi = INT_MIN;
//             for(int ind = i; ind<=j; ind++){
//                 int cost = arr[i-1]*arr[ind]*arr[j+1]+
//                 dp[i][ind-1]+dp[ind+1][j];
//                 maxi = max(maxi, cost);
//             }dp[i][j] = maxi;
//         }
//     }return dp[1][n];
// }


// int main(){
//     int n; cin>>n;
//     vector<int> arr(n, 0);
//     for(int i = 0; i<n; i++) cin>>arr[i];
//     cout<<maxCoins(arr);
//     return 0;
// }
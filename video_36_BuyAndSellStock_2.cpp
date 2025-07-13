// #include<iostream>
// #include<bits/stdc++.h>
// using namespace std;

/* ALL STOCKS RELATED PROBLEMS REQUIRES HANDELLING OF SPACE COMPLEXITY */

/********************************************** MEMOIZATION ************************************************ */
// long solve(int ind, int buy, long *arr, int n, vector<vector<long>> &dp){
//     if(ind == n) return 0;
//     if(dp[ind][buy] != -1) return dp[ind][buy];

//     long profit = 0;
//     if(buy)
//         profit = max(-arr[ind]+solve(ind+1, 0, arr, n, dp),
//         solve(ind+1, 1, arr, n, dp));
//     else 
//         profit = max(arr[ind]+solve(ind+1, 1, arr, n, dp),
//         solve(ind+1, 0, arr, n, dp));
//     return dp[ind][buy] = profit;
// }
// long getMaximumProfit(long *values, int n){
//     //Write your code here
//     if(n == 0) return 0;
//     vector<vector<long>> dp(n, vector<long> (2, -1));
//     return solve(0, 1, values, n, dp);
// }

/************************************************ MAIN **************************************************** */
// int main(){
//     int n; 
//     cin>>n;
//     long arr[n] = {0};
//     for(int i = 0; i<n; i++) cin>>arr[i];
//     cout<<getMaximumProfit(arr, n);
//     return 0;
// }
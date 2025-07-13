// #include<iostream>
// #include<bits/stdc++.h>
// using namespace std;
/****************************************************** MEMOIZATION ********************************************** */
// int solve(vector<int> &arr, int sum, int index, vector<vector<int>> &dp) {   
//     if(index < 0) 
//         return (sum == 0);
//     if(dp[index][sum] != -1) 
//         return dp[index][sum];
//     int notPick = solve(arr, sum, index - 1, dp);
//     int pick = 0;
//     if(arr[index] <= sum)
//         pick = solve(arr, sum - arr[index], index - 1, dp);
//     dp[index][sum] = (pick + notPick) % 1000000007;
//     return dp[index][sum];
// }

// int findWays(vector<int>& arr, int k){
//     int n = arr.size();
//     vector<vector<int>> dp(n, vector<int>(k + 1, -1)); 
//     return solve(arr, k, n - 1, dp);
// }
/******************************************************** TABULATION ********************************************** */
// int findWays(vector<int>& arr, int k)
// {
// 	// Write your code here.
//     int n = arr.size();
//     vector<vector<int>> dp(n, vector<int> (k+1, 0));
//     for(int j=0;j<=k;j++){
//         if(arr[0]==0)dp[0][arr[0]]=2;
//         else if(arr[0]==j)dp[0][j]=1;
//     }
//     if(arr[0] != 0 && arr[0]<=k) dp[0][arr[0]] = 1;
//     for(int ind = 1; ind<n; ind++){
//         for(int target = 0; target<=k; target++){
//             int ntake = dp[ind-1][target];
//             int take = 0; 
//             if(arr[ind]<=target)
//             take = dp[ind-1][target-arr[ind]];

//             dp[ind][target] = (take+ntake)%1000000007;
//         }
//     }
//     return dp[n-1][k];
// }

// int main(){
//     int k, n;
//     vector<int> arr(n);
//     cin>>n>>k;
//     for(int i = 0; i<n; i++){
//         cin>>arr[i];
//     }
//     cout<<findWays(arr, k);
//     return 0;
// }
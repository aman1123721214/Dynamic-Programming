//  #include<iostream>
//  #include<bits/stdc++.h>
//  using namespace std;

/**************************************************** MEMOIZATION ***************************************************************/
//  int solve(vector<int> &weight, vector<int> &value, int ind, int maxWeight, vector<vector<int>> &dp){
//     if(ind == 0 ){
//         if(weight[0]<=maxWeight) return value[0];
//         else return 0;
//     }
//     if(dp[ind][maxWeight] != -1) return dp[ind][maxWeight];
//     int ntake = solve(weight, value, ind-1, maxWeight, dp);
//     int take = -1e9;
//     if(weight[ind]<=maxWeight)
//     take = value[ind]+solve(weight, value, ind-1, maxWeight-weight[ind], dp);

//     return dp[ind][maxWeight]=max(take, ntake);

//  }
//  int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) {
//     // Write your code here
//     vector<vector<int>> dp(n, vector<int> (maxWeight+1, -1));
//     return solve(weight, value, n-1, maxWeight, dp);
// }

/********************************************* TABULATION / MAX SPACE OPTIMIZATION *********************************************/
// int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
// {
// 	// Write your code here
//     vector<int> prev(maxWeight+1, 0), curr(maxWeight+1, 0);
//     for(int w = weight[0]; w<=maxWeight; w++) prev[w] = value[0];

//     for(int ind = 1; ind<n; ind++){
//         for(int w = maxWeight; w>=0; w--){
//             int ntake = prev[w];
//             int take = -1e9;
//             if(weight[ind]<= w)
//             take = value[ind]+prev[w-weight[ind]];
//             curr[w] = max(take, ntake);
//         }
//         prev = curr;
//     }
//     return prev[maxWeight];
// }
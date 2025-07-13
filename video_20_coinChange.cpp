// #include<iostream>
// #include<bits/stdc++.h>
// using namespace std;

/****************************************** MEMOIZATION *********************************************** */
// int solve(int ind, vector<int> &coins, int target, vector<vector<int>> &dp){
//     if(ind == 0){
//         if(target%coins[ind] == 0) return target/coins[ind];
//         return 1e9;
//     }
//     if(dp[ind][target] != -1) return dp[ind][target];

//     int ntake = solve(ind-1, coins, target, dp);
//     int take = 1e9;
//     if(coins[ind]<=target)
//     take = 1+solve(ind, coins, target-coins[ind], dp);

//     return dp[ind][target] = min(take, ntake);
// }

// int minimumElements(vector<int> &num, int x)
// {
//     // Write your code here.  
//     int n = num.size(), ans;
//     vector<vector<int>> dp(n, vector<int> (x+1, -1)); 
//     ans = solve(n-1, num, x, dp);
//     if(ans>=1e9) return -1;
//     return ans;
// }

/***************************************** TABULATION ************************************************ */
// int minimumElements(vector<int> &nums, int target)
// {
//     // Write your code here.
//     int n = nums.size();
//     vector<vector<int>> dp(n, vector<int> (target+1, 0));

//     for(int t = 0; t<=target; t++){
//         if(t%nums[0] == 0) dp[0][t] = t/nums[0];
//         dp[0][t] = 1e9;
//     }
    
//     for(int ind = 1; ind<n; ind++){
//         for(int t = 1; t<=target; t++){
//             int ntake = dp[ind-1][t];
//             int take = 1e9;
//             if(nums[ind]<=t)
//                 take = 1+dp[ind][t-nums[ind]];
//             dp[ind][t] = min(take, ntake);
//         }
//     }
//     int ans = dp[n-1][target];
//     if(ans>=1e9) return -1;
//     return ans;
// }

/******************************************** MAIN ************************************************** */
// int main(){
//     int x, n;
//     cin>>x>>n;
//     vector<int> num(n);
//     for(int i = 0; i<n; i++)
//     cin>>num[i];
//     cout<<minimumElements(num, x);
// }
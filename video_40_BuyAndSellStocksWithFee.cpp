// #include<iostream>
// #include<bits/stdc++.h>
// using namespace std;

/******************************************* MEMOIZATION ******************************************************** */
// int solve(int ind, int buy, int fee, int n, vector<int> &arr, vector<vector<int>> &dp){
//     if(ind == n) return 0;
//     if(dp[ind][buy] != -1) return dp[ind][buy];

//     if(buy) return 
//     dp[ind][buy] = max(-arr[ind]+solve(ind+1, 0, fee, n, arr, dp), solve(ind+1, 1, fee, n, arr, dp));
//     else return 
//     dp[ind][buy] = max(arr[ind]-fee+solve(ind+1, 1, fee, n, arr, dp), solve(ind+1, 0, fee, n, arr, dp));

// }
// int maximumProfit(vector<int> &prices, int n, int fee){
// 	// Write your code here.
//     //only two varying quantity ie index and buy
//     vector<vector<int>> dp(n, vector<int> (2, -1));
//     return solve(0, 1, fee, n, prices, dp); 
// }

/******************************************** TABULATION ******************************************************** */
// int maximumProfit(vector<int> &arr, int n, int fee){
// 	// Write your code here.
//     //only two varying quantity ie index and buy
//     vector<vector<int>> dp(n+1, vector<int> (2, 0));
//     for(int ind = n-1; ind>=0; ind--){
//         for(int buy = 0; buy<=1; buy++){
//             if(buy == 1) dp[ind][buy] = max(-arr[ind]+dp[ind+1][0], dp[ind+1][1]);
//             else 
//             dp[ind][buy] = max(arr[ind]-fee+dp[ind+1][1], dp[ind+1][0]);
//         }
//     }return dp[0][1]; 
// }

/********************************************* MAX SPACE OPT **************************************************** */
// int maximumProfit(vector<int> &arr, int n, int fee){
// 	// Write your code here.
//     //only two varying quantity ie index and buy
//     vector<int> after(2, 0), curr(2, 0);
//     for(int ind = n-1; ind>=0; ind--){
//         for(int buy = 0; buy<=1; buy++){
//             if(buy == 1) curr[buy] = max(-arr[ind]+after[0], after[1]);
//             else 
//             curr[buy] = max(arr[ind]-fee+after[1], after[0]);
//         }
//         after = curr;
//     }return after[1]; 
// }

/******************************************** MAIN ************************************************************* */
// int main(){
//     int n, fee;
//     cin>>n>>fee;
//     vector<int> arr(n, 0);
//     for(int i = 0; i<n; i++) cin>>arr[i];
//     cout<<maximumProfit(arr, n, fee);
//     return 0;
// }

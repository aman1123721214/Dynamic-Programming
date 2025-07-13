// #include<iostream>
// #include<bits/stdc++.h>
// using namespace std;

/********************************************* MEMOIZATION **************************************************** */
// STOCKS WITH COOLDOWN EFFECT ie YOU CAN'T BUY STOCKS IMMEDIATELY AFTER SELLING PREVIOUS ONE

// int solve(int ind, vector<int> &arr, int buy, vector<vector<int>> &dp){
//     int n = arr.size();
//     if(ind >= n) return 0;
//     if(dp[ind][buy] != -1) return dp[ind][buy];
    // if(buy) return
    //     dp[ind][buy] = max(-arr[ind]+solve(ind+1, arr, 0, dp), solve(ind+1, arr, 1, dp));
    // else return
    //     dp[ind][buy] = max(arr[ind]+solve(ind+2, arr, 1, dp), solve(ind+1, arr, 0, dp));         
// }
// int stockProfit(vector<int> &prices){
//     // Write your code here.
//     int n = prices.size();
//     vector<vector<int>> dp(n, vector<int> (2, -1));
//     return solve(0, prices, 1, dp);
// }

/****************************************** TABULATION ******************************************************** */

// int stockProfit(vector<int> &arr){
//     // Write your code here.
//     int n = arr.size();
//     vector<vector<int>> dp(n+2, vector<int> (2, 0));//n+2 because we are here dealing with ind+2 also;
//     //No pint to write base case because the dp array is initialized to zero itself satisfying the base case
//     //dp[n-1][0] = 0; dp[n-1][1] = 0;
//     for(int ind = n-1; ind>=0; ind--){
//         for(int buy = 0; buy<=1; buy++){
//             if(buy == 1) 
//                 dp[ind][buy] = max(-arr[ind]+dp[ind+1][0], dp[ind+1][1]);
//             else
//                 dp[ind][buy] = max(arr[ind]+dp[ind+2][1], dp[ind+1][0]);
//         }
//     }
//     return dp[0][1]; 
// }

/****************************************** MAIN ************************************************************** */

// int main(){
//     int n;
//     cin>>n;
//     vector<int> arr(n, 0);
//     for(int i = 0; i<n; i++) cin>>arr[i];
//     cout<<stockProfit(arr);
//     return 0;
// }
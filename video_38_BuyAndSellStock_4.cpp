#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*************************** TRANSACTIONS ON STOCKS SHOULD BE ATMOST 'K' TIMES************************************** */
// SIMILAR TO STOCKS-4 EXCEPT THE CAP WOULD BE REPLACED BY 'K' INSTEAD OF 2

/********************************************** MEMOIZATION ******************************************************** */
// int solve(int ind, int k, int buy, vector<int> &arr, vector<vector<vector<int>>> &dp){
//     if(ind == arr.size() || k == 0) return 0;
//     if(dp[ind][buy][k] != -1) return dp[ind][buy][k];
//     if(buy) return 
//         dp[ind][buy][k] = max(-arr[ind]+solve(ind+1, k, 0, arr, dp), solve(ind+1, k, 1, arr, dp));
//     else return 
//         dp[ind][buy][k] = max(arr[ind]+solve(ind+1, k-1, 1, arr, dp), solve(ind+1, k, 0, arr, dp));
//     return dp[ind][buy][k] ;
// }
// int maximumProfit(vector<int> &prices, int n, int k){
//     // Write your code here.
//     //since there are 3 varying quantities ie index, cap = k, buy/notBuy hence 3d DP vector
//     vector<vector<vector<int>>> dp(n, vector<vector<int>> (2, vector<int> (k+1, -1)));  
//     return solve(0, k, 1, prices, dp);
// }

/*********************************************** TABULATION ******************************************************* */

int maximumProfit(vector<int> &arr, int n, int k){
    // Write your code here.
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (2, vector<int> (k+1, 0))); 
    
    for(int ind = n-1;ind>=0; ind--){
        for(int buy = 0; buy<=1; buy++){
            for(int cap = 1; cap<=k; cap++){
                if(buy == 1) 
                    dp[ind][buy][cap] = max(-arr[ind]+dp[ind+1][0][cap], dp[ind+1][1][cap]);
                else  
                    dp[ind][buy][cap] = max(arr[ind]+dp[ind+1][1][cap-1], dp[ind+1][0][cap]);
            }
        }
    }
    return dp[0][1][k];
}

/*********************************************** MAX SPACE OPT **************************************************** */
// int maximumProfit(vector<int> &arr, int n, int k)
// {
//     // Write your code here.
//     //since there is 3 changing parameters ie n, buy, cap so we have to take 3d dp
//     vector<vector<int>> after(2, vector<int> (k+1, 0));
//     vector<vector<int>> curr(2, vector<int> (k+1, 0));

//     for(int ind = n-1; ind>=0; ind--){
//         for(int buy = 0; buy<=1; buy++){
//             for(int cap = 1  ; cap<=k; cap++){
//                 if(buy == 1) 
//                     curr[1][cap] = max(-arr[ind]+after[0][cap], after[1][cap]);
//                 else
//                     curr[buy][cap] = max(arr[ind]+after[1][cap-1], after[0][cap]);
//             }
//         }after = curr;
//     }
//     return after[1][k];
// }

/*********************************************** MAIN ************************************************************** */
int main(){
    int n, k;
    cin>>n>>k;
    vector<int> arr(n, 0);
    for(int i = 0; i<n; i++) cin>>arr[i];
    cout<<maximumProfit(arr, n, k);
    return 0;
}
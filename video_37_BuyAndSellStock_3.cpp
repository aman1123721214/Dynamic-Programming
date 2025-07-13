// #include<iostream>
// #include<bits/stdc++.h>
// using namespace std;

/************************************************* MEMOIZATION ********************************************************** */
// int solve(int ind, int buy, vector<int> &arr, int cap, vector<vector<vector<int>>> &dp){
//     if(cap == 0 || ind == arr.size()) return 0;
    
//     if(dp[ind][buy][cap] != -1) return dp[ind][buy][cap];
    // if(buy) return 
    //     dp[ind][buy][cap] = max(-arr[ind]+solve(ind+1, 0, arr, cap, dp), solve(ind+1, 1, arr, cap, dp));
    // else return
    //     dp[ind][buy][cap] = max(arr[ind]+solve(ind+1, 1, arr, cap-1, dp), solve(ind+1, 0, arr, cap, dp));
    // return dp[ind][buy][cap];
// }
// int maxProfit(vector<int>& prices){
//     // Write your code here.
//     int n = prices.size();
//     //since there is 3 changing parameters ie n, buy, cap so we have to take 3d dp
//     vector<vector<vector<int>>> dp(n, vector<vector<int>> (2, vector<int> (3, -1)));
//     return solve(0, 1, prices, 2, dp);
// }

/************************************************ TABULATION ************************************************************ */

// int maxProfit(vector<int>& arr){
//     // Write your code here.
//     int n = arr.size();
//     //since there is 3 changing parameters ie n, buy, cap so we have to take 3d dp
//     vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (2, vector<int> (3, 0)));
    // writing the base cases 
    // for(int ind = 0; ind<n; ind++){
    //     for(int buy = 0; buy<=1; buy++) dp[ind][buy][0] = 0;
    // }

    // for(int buy = 0; buy<=1; buy++){
    //     for(int cap = 0; cap<=2; cap++) dp[n-1][buy][cap] = 0;
    // }

    //we can also not write the base cases because the vector is already initialized with 0


//     for(int ind = n-1; ind>=0; ind--){
//         for(int buy = 0; buy<=1; buy++){
//             for(int cap = 1  ; cap<=2; cap++){
//                 if(buy == 1) 
//                     dp[ind][1][cap] = max(-arr[ind]+dp[ind+1][0][cap], dp[ind+1][1][cap]);
//                 else
//                     dp[ind][buy][cap] = max(arr[ind]+dp[ind+1][1][cap-1], dp[ind+1][0][cap]);
//             }
//         }
//     }
//     return dp[0][1][2];
// }

/*********************************************** MAX SPACE OPT ****************************************************** */

// int maxProfit(vector<int>& arr){
    // // Write your code here.
    // int n = arr.size();
    // //since there is 3 changing parameters ie n, buy, cap so we have to take 3d dp
    // vector<vector<int>> after(2, vector<int> (3, 0));
    // vector<vector<int>> curr(2, vector<int> (3, 0));

    // for(int ind = n-1; ind>=0; ind--){
    //     for(int buy = 0; buy<=1; buy++){
    //         for(int cap = 1  ; cap<=2; cap++){
    //             if(buy == 1) 
    //                 curr[1][cap] = max(-arr[ind]+after[0][cap], after[1][cap]);
    //             else
    //                 curr[buy][cap] = max(arr[ind]+after[1][cap-1], after[0][cap]);
    //         }
    //     }after = curr;
    // }
    // return after[1][2];
// }

/********************************************* MAIN *************************************************************** */

// int main(){
//     int n; cin>>n;
//     vector<int> arr(n, 0);
//     for(int i = 0; i<n; i++) cin>>arr[i];
//     cout<<maxProfit(arr);
//     return 0;
// }
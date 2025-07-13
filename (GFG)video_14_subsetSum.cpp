// #include<iostream>
// #include<bits/stdc++.h>
// using namespace std;
/************************************* MEMOIZATION ****************************************** */
// bool solve(int ind, int tar, vector<int> &arr, vector<vector<int>> &dp){
//     if(tar == 0) return 1;
//     if(ind == 0) return (tar == arr[ind]);
//     if(dp[ind][tar] != -1) return dp[ind][tar];

//     bool ntake = solve(ind-1, tar, arr, dp);
//     bool take = 0;
//     if(arr[ind]<=tar)
//     take = solve(ind-1, tar-arr[ind], arr, dp);

//     return dp[ind][tar] = take||ntake;
// }
// bool isSubsetSum(vector<int>arr, int sum){
//     // code here 
//     int n = arr.size();
//     vector<vector<int>> dp(n, vector<int> (sum+1, -1));
//     return solve(n-1, sum, arr, dp);
// }

/************************************** TABULATION ******************************************* */
// bool isSubsetSum(vector<int>arr, int sum){
//     // code here
    // int n = arr.size();
    // vector<vector<bool>> dp(n, vector<bool> (sum+1, 0));
    // for(int i = 0; i<n; i++) dp[i][0] = 1;
    // dp[0][arr[0]] = 1;

    // for(int ind = 1; ind<n; ind++){
    //     for(int tar = 1; tar<=sum; tar++){
    //         bool ntake = dp[ind-1][tar];
    //         bool take = 0; 
    //         if(arr[ind]<=tar)
    //         take = dp[ind-1][tar-arr[ind]];

    //         dp[ind][tar] = take||ntake;
    //     }
    // }return dp[n-1][sum];
// }

/******************************************* MAIN ********************************************* */
// int main(){
//     int sum, n;
//     cin>>n>>sum;
//     vector<int> arr(n, 0);
//     for(int i = 0; i<n; i++){
//         cin>>arr[i];
//     }
//     cout<<isSubsetSum(arr, sum);
// }
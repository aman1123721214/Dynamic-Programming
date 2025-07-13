// #include<iostream>
// #include<bits/stdc++.h>
// using namespace std;

/************************************************ MEMOIZATION ******************************************** */
// bool solve(int ind, int target, vector<int> &arr, vector<vector<int>> &dp){
//     if(!target) return 1;
//     if(!ind) return (arr[0] == target);
//     if(dp[ind][target] != -1) return dp[ind][target];

//     bool ntake = solve(ind-1, target, arr, dp);
//     bool take = 0;
//     if(arr[ind]<=target) 
//     take = solve(ind-1, target-arr[ind], arr, dp);

//     return dp[ind][target] = take || ntake;
// }
// bool canPartition(vector<int> &arr, int n)
// {
// 	// Write your code here.
//     if(n == 1) return 0;
//     int sum = 0, target;
//     for(auto it : arr) sum+=it;
//     if(sum%2) return 0;
//     target = sum/2;
//     vector<vector<int>> dp(n, vector<int> (target+1, -1));
//     return solve(n-1, sum/2, arr, dp);
// }

/************************************************** TABULATION ******************************************* */
// bool canPartition(vector<int> &arr, int n)
// {
// 	// Write your code here.
//     if(n == 1) return 0; 
//     int sum = 0;
//     for(auto it:arr) sum += it;
//     if(sum%2) return 0;

//     vector<vector<bool>> dp(n, vector<bool> ((sum/2)+1, 0));
//     for(int ind = 0; ind<n; ind++) dp[ind][0] = 1;
//     dp[0][arr[0]] = 1;

//     for(int ind = 1; ind<n; ind++){
//         for(int target = 1; target<=sum/2; target++){
//             bool ntake = dp[ind-1][target];
//             bool take = 0;
//             if(arr[ind]<=target)
//             take = dp[ind-1][target-arr[ind]];

//             dp[ind][target] = take || ntake;
//         }
//     }
//     return dp[n-1][sum/2];
// }

/************************************************* MAIN *************************************************** */
// int main(){
//     int n;
//     vector<int> arr(n);
//     cin>>n;
//     for(int i = 0; i<n; i++){
//         cin>>arr[i];
//     }
//     cout<<canPartition(arr, n);
// }
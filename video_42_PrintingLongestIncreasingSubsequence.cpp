// #include<iostream>
// #include<bits/stdc++.h>
// using namespace std;

/********************************************** LENGTH OF LIS *********************************************** */
// int longestIncreasingSubsequence(int arr[], int n){
//     // Write Your Code here
//     int maxi = 1;
//     vector<int> dp(n, 1);

//     for(int ind = 0; ind<n; ind++){
//         for(int prev_ind = 0; prev_ind<ind; prev_ind++){
//             if(arr[prev_ind]<arr[ind]){
//                 dp[ind] = max(dp[ind], 1+dp[prev_ind]);
//             }
//         }maxi = max(maxi, dp[ind]);
//     }return maxi;
// }

/********************************************** PRINTING THE LIS ******************************************** */
// int longestIncreasingSubsequence(int arr[], int n){
//     // Write Your Code here
//     int maxi = 1, lastInd = 0;
//     vector<int> dp(n, 1), mp(n, 0);

//     for(int ind = 0; ind<n; ind++){
//         mp[ind] = ind;
//         for(int prev_ind = 0; prev_ind<ind; prev_ind++){
//             if(arr[prev_ind]<arr[ind]){
//                 if(1+dp[prev_ind]>dp[ind]){
//                     dp[ind] = 1+dp[prev_ind];
//                     mp[ind] = prev_ind;
//             }
//         }
//         if(dp[ind]>maxi){
//             maxi = dp[ind];
//             lastInd = ind;
//         }
//     }
//     while(mp[lastInd] != lastInd)
//     return maxi;
// }

// int main(){
//     int n, cin>>n;
//     int *arr = new int[n];
//     for(int i = 0; i<n; i++) cin>>arr[i];
//     cout<<longestIncreasingSubsequence(arr, n);
//     return 0;
// }
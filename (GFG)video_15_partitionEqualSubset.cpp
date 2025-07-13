// #include<iostream>
// #include<bits/stdc++.h>
// using namespace std;

// int equalPartition(int n, int arr[])
// {
//     // code here
//     if(n == 1) return 0;
//     int sum = 0;
//     for(int i = 0; i<n; i++) sum+=arr[i];
//     if(sum%2) return 0;
//     vector<vector<bool>> dp(n, vector<bool> ((sum/2)+1, 0));
//     for(int ind = 0; ind<n; ind++) dp[ind][0] = 1;
//     dp[0][arr[0]] = 1;

//     for(int ind = 1; ind<n; ind++){
//         for(int tar = 1; tar<=sum/2; tar++){
//             bool ntake = dp[ind-1][tar];
//             bool take = 0;
//             if(arr[ind]<=tar)
//             take = dp[ind-1][tar-arr[ind]];

//             dp[ind][tar] = ntake||take;
//         }
//     }return dp[n-1][sum/2];
// }
// int main(){
//     int n; cin>>n;
//     int arr[n] = {0};
//     for(int i = 0; i<n; i++) cin>>arr[i];
//     cout<<equalPartition(n, arr);
// }
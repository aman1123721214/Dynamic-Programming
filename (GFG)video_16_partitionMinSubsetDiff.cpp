// #include<iostream>
// #include<bits/stdc++.h>
// using namespace std;

/***************************************** TABULATION ****************************************** */
// int minDifference(int arr[], int n)  { 
// 	// Your code goes here
//     int sum = 0;
//     for(int i = 0; i<n; i++) sum+=arr[i];
    
//     vector<vector<bool>> dp(n, vector<bool> (sum+1, 0));
//     for(int i = 0; i<n; i++) dp[i][0] = 1;
//     dp[0][arr[0]] = 1;

//     for(int ind = 1; ind<n; ind++){
//         for(int tar = 1; tar<=sum; tar++){
//             bool ntake = dp[ind-1][tar];
//             bool take = 0;
//             if(arr[ind]<=tar)
//             take = dp[ind-1][tar-arr[ind]];

//             dp[ind][tar] = take || ntake;
//         }
//     }
//     int ans = 1e9;
//     for(int tar = 0; tar<=sum/2; tar++){
//         if(dp[n-1][tar] == 1)
//             ans = min(ans, abs(sum-2*tar));
//     }
//     return ans;
// } 

/****************************************** MAX SPACE OPT *************************************** */
// int minDifference(int arr[], int n)  { 
// 	// Your code goes here
//     int sum = 0;
//     for(int i = 0; i<n; i++) sum+=arr[i];
    
//     vector<bool> prev(sum+1, 0), curr(sum+1, 0);
//     prev[0] = 1, curr[0] = 1;
//     prev[arr[0]] = 1;

//     for(int ind = 1; ind<n; ind++){
//         for(int tar = 1; tar<=sum; tar++){
//             bool ntake = prev[tar];
//             bool take = 0;
//             if(arr[ind]<=tar)
//             take = prev[tar-arr[ind]];

//             curr[tar] = take || ntake;
//         }prev = curr;
//     }

//     int ans = 1e9;
//     for(int tar = 0; tar<=sum/2; tar++){
//         if(prev[tar] == 1) ans = min(ans, abs(sum-2*tar));
//     }
//     return ans;
// } 

/******************************************** MAIN *********************************************** */
// int main(){
//     int n; cin>>n;
//     int arr[n] = {0};
//     for(int i = 0; i<n; i++) cin>>arr[i];
//     cout<<minDifference(arr, n);
//     return 0;
// }
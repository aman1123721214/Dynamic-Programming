// #include<iostream>
// #include<bits/stdc++.h>
// using namespace std;
// int solve(vector<int>& arr, int k)
// {
// 	// Write your code here.
//     int n = arr.size();
//     vector<vector<int>> dp(n, vector<int> (k+1, 0));
//     for(int j=0;j<=k;j++){
//         if(arr[0]==0)dp[0][arr[0]]=2;
//         else if(arr[0]==j)dp[0][j]=1;
//     }
//     if(arr[0] != 0 && arr[0]<=k) dp[0][arr[0]] = 1;
//     for(int ind = 1; ind<n; ind++){
//         for(int target = 0; target<=k; target++){
//             int ntake = dp[ind-1][target];
//             int take = 0; 
//             if(arr[ind]<=target)
//             take = dp[ind-1][target-arr[ind]];

//             dp[ind][target] = (take+ntake)%1000000007;
//         }
//     }
//     return dp[n-1][k];
// }
// int countPartitions(int n, int d, vector<int> &arr){
//     int sum = 0;
//     for(auto it: arr) sum+=it;
//     if((sum-d) <0 || (sum-d) % 2) return 0;
//     int k = (sum-d)/2;
//     return solve(arr, k);
// }
// int main(){
//     int n, d;
//     cin>>n>>d;
//     vector<int> arr(n, 0);
//     for(int i = 0; i<n; i++) cin>>arr[i];
//     cout<<countPartitions(n, d, arr);
//     return 0;
// }
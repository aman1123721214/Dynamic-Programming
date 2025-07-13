// #include<iostream>
// #include<bits/stdc++.h>
// using namespace std;

// the seq can either be inc only or dec only or both (ie inc from one end & then dec)

// int longestBitonicSubsequence(vector<int>& arr, int n){
// 	// Write your code here.
//     vector<int> dp1(n, 1);

//     // inc length sub-seq from front
//     for(int i = 0; i<n; i++){
//         for(int prev = 0; prev<i; prev++){
//             if(arr[prev]<arr[i] && 1+dp1[prev]>dp1[i])
//                 dp1[i] = max(dp1[i], 1+dp1[prev]);
//         }
//     }
    
//     // inc length sub-seq from back
//     vector<int> dp2(n, 1);
//     for(int i = n-1; i>=0; i--){
//         for(int front = n-1; front>i; front--){
//             if(arr[front]<arr[i] && 1+dp2[front]>dp2[i])
//                 dp2[i] = max(dp2[i], 1+dp2[front]);
//         }
//     }

//     // traversing the dp1 & dp2 simultaneously
//     int ans = 1;
//     for(int i = 0; i<n; i++){
//         ans = max(ans, dp1[i]+dp2[i]-1);
//     } return ans;
// }

// int main(){
//     int n;cin>>n;
//     vector<int> arr(n, 0);
//     for(int i = 0; i<n; i++) cin>>arr[i];
//     cout<<longestBitonicSubsequence(arr, n);
//     return 0;
// }
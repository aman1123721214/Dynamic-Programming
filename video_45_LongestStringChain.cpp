// #include<iostream>
// #include<bits/stdc++.h>
// using namespace std;
// bool compare(string &s1, string &s2){
//     return s1.size()<s2.size();
// }

// bool checkPossible(string &s1, string &s2){
//     if(s1.size() != s2.size()+1) return 0;
//     int first = 0, second = 0;

//     while(first<s1.size()){
//         if(s1[first] == s2[second]){
//             first++;
//             second++;
//         }
//         else first++;
//     }
//     if(first == s1.size() && second == s2.size()) return 1;
//     return 0;
// }

// int longestStrChain(vector<string> &arr){
//     // Write your code here.
//     sort(arr.begin(), arr.end(), compare);    // lexicographically inc length
//     int n = arr.size();
//     int maxi = 1;

//     vector<int> dp(n, 1);
//     for(int i = 0; i<n; i++){
//         for(int prev = 0; prev<i; prev++){
//             if(checkPossible(arr[i], arr[prev])){
//                 if(1+dp[prev]>dp[i]){
//                     dp[i] = 1+dp[prev];
//                     maxi = max(maxi, dp[i]);
//                 }
//             }
//         }
//     }return maxi;
// }

// int main(){
//     int n; cin>>n;
//     vector<string> arr(n,  "");
//     for(int i = 0; i<n; i++) cin>>arr[i];
//     cout<<longestStrChain(arr);
//     return 0;
// }
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/***************************************** FRONT PARTITIONING DP **************************************** */

/***************************************** MEMOIZATION ************************************************** */
// bool isPalind(string str){
//     int i = 0, j = str.size()-1;
//     while(i<j){
//         if(str[i] != str[j]) return 0;
//         i++, j--;
//     }return 1;
// }
// int solve(int i, int n, string &str, vector<int> &dp){
//     if(i == n) return 0;
//     if(dp[i] != -1) return dp[i];
//     int ans = 1e9;
//     string temp = "";
//     for(int j = i; j<n; j++){
//         temp+=str[j];
//         if(isPalind(temp)){
//             int cost = 1+solve(j+1, n, str, dp);
//             ans  = min(ans, cost);
//         }
//     }return dp[i]  = ans;
// }
// int palindromePartitioning(string str){
//     // Write your code here
//     int n = str.size();
//     vector<int> dp(n, -1);
//     return solve(0, n, str, dp)-1;
// }
bool isPalind(string str){
    int i = 0, j = str.size()-1;
    while(i<j){
        if(str[i] != str[j]) return 0;
        i++, j--;
    }return 1;
}
int palindromePartitioning(string str){
    // Write your code here
    int n = str.size();
    vector<int> dp(n+1, 0);
    dp[n] = 0;
    for(int i = n-1; i>=0; i--){
        int ans = 1e9;
        string temp = "";
        for(int j = i; j<n; j++){
            temp+=str[j];
            if(isPalind(temp)){
                int cost = 1+dp[j+1];
                ans  = min(ans, cost);
            }
        }dp[i] = ans;
    }return dp[0]-1;
}
int main(){
    string str;
    cin>>str;
    cout<<palindromePartitioning(str);
    return 0;
}
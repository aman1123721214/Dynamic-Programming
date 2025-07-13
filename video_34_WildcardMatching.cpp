// #include<iostream>
// #include<bits/stdc++.h>
// using namespace std;

/******************************************** MEMOIZATION ************************************************ */
// bool solve(int i, int j, string &s, string &t, vector<vector<int>> &dp){
//     if(i<0 && j<0) return 1;
//     if(i<0 && j>=0) return 0;
//     if(i>=0 && j<0){
//         for(int i1 = 0; i1<=i; i1++){
//             if(s[i1] != '*') return 0;
//             return 1;
//         }
//     }
//     if(dp[i][j] != -1) return dp[i][j];

    // if(s[i] == t[j] || s[i] == '?') 
    //     return dp[i][j] = solve(i-1, j-1, s, t, dp);
    // if(s[i] == '*') 
    //     return dp[i][j] = solve(i, j-1, s, t, dp) || solve(i-1, j, s, t, dp);
    // return dp[i][j] = 0;
// }
// bool wildcardMatching(string pattern, string text){
//    // Write your code here.
//    int n = pattern.size(), m = text.size();
//    vector<vector<int>> dp(n, vector<int> (m, -1));
//    return solve(n-1, m-1, pattern, text, dp);
// }

/********************************************* TABULATION ************************************************ */
// bool wildcardMatching(string pattern, string text){
//    // Write your code here.
//    int n = pattern.size(), m = text.size();
//    vector<vector<bool>> dp(n+1, vector<bool> (m+1, 0));
//    dp[0][0] = 1;
//    for(int j = 1; j<=m; j++) dp[0][j] = 0;
   
//    for(int i = 1; i<=n; i++){
//     bool flag = 1;
//     for(int i1 = 1; i1<=i; i1++){
//         if(pattern[i1-1] != '*') {
//             flag = 0;
//             break;
//         }
//     }dp[i][0] = flag;
//    }
    
//     for(int i = 1; i<=n; i++){
//         for(int j = 1; j<=m; j++){
//             if(pattern[i-1] == text[j-1] || pattern[i-1] == '?') 
//                 dp[i][j] = dp[i-1][j-1];
//             else if(pattern[i-1] == '*') 
//                 dp[i][j] = dp[i][j-1] || dp[i-1][j];
//             else dp[i][j] = 0;
//         }
//     }
//     return dp[n][m];
// }

// int main(){
//     string pattern, text;
//     cin>>pattern>>text;
//     cout<<wildcardMatching(pattern, text);
//     return 0;
// }
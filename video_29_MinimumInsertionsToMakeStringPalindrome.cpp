// #include<iostream>
// #include<bits/stdc++.h>
// using namespace std;

// FUNCTION TO FIND LONGEST COMMON PALINDROMIC SUBSEQUENCE
// int LCPS(string s1, string s2){
//     int n = s1.size();
//     vector<vector<int>> dp(n+1, vector<int> (n+1, 0));
//     for(int row = 0; row<=n; row++) dp[row][0] = 0;
//     for(int col = 0; col<=n; col++) dp[0][col] = 0;
//     int ans = 0;
//     for(int i = 1; i<=n; i++){
//         for(int j = 1; j<=n; j++){
//             if(s1[i-1] == s2[j-1]){
//                 dp[i][j] = 1+dp[i-1][j-1];
//                 ans = max(ans, dp[i][j]);
//             }
//             else
//                 dp[i][j] = max(dp[i-1][j], dp[i][j-1]); 
//         }
//     }
//     return ans;
// }

// int minimumInsertions(string &str)
// {
// 	// Write your code here.
//     int n = str.size();
//     string s2 = str;
//     reverse(s2.begin(), s2.end()); // s2 is reverse of str given
//     return n-LCPS(str, s2);
// }

// int main(){
//     string str;
//     cin>>str;
//     cout<<minimumInsertions(str);
//     return 0;
// }
// #include<iostream>
// #include<bits/stdc++.h>
// using namespace std;

// int lcs(string str1, string str2){
//     int n = str1.size(), m = str2.size();
//     int ans = 0;
//     vector<vector<int>> dp(n+1, vector<int> (m+1, 0));

//     for(int i = 0; i<=n; i++) dp[i][0] = 0;
//     for(int j = 0; j<=m; j++) dp[0][j] = 0;

//     for(int i = 1; i<=n; i++){
//         for(int j = 1; j<=m; j++){
//             if(str1[i-1] == str2[j-1]){
//                 dp[i][j] = 1+dp[i-1][j-1];
//                 ans = max(ans, dp[i][j]);
//             }
//             else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
//         }
//     }
//     // for(int i = 0; i<=n; i++){
//     //         for(int j = 0; j<=m; j++) cout<<" "<<dp[i][j];
//     //     cout<<endl;
//     // }
//     return ans;
// }
// int longestPalindromeSubsequence(string str1)
// {
//     // Write your code here.
//     string str2 = str1;
//     reverse(str2.begin(), str2.end());
//     return lcs(str1, str2); 
// }

// int main(){
//     string str;
//     cin>>str;
//     cout<<longestPalindromeSubsequence(str);
//     return 0;
// }

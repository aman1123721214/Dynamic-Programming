// #include<iostream>
// #include<bits/stdc++.h>
// using namespace std;

// int lcs(string &str1, string &str2){
    // Write your code here.
    // int n = str1.size(), m = str2.size();
    // vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
    // for(int i = 0; i<=n; i++) dp[i][0] = 0;
    // for(int j = 0; j<=m; j++) dp[0][j] = 0;
    // int ans = 0;
    // for(int i = 1; i<=n; i++){
    //     for(int j = 1; j<=m; j++){
    //         if(str1[i-1] == str2[j-1]){
    //             dp[i][j] = 1+dp[i-1][j-1];
    //             ans = max(ans, dp[i][j]);
    //         }

    //         else dp[i][j] = 0;
    //     }      
    // }
    // return ans;
// }
// int main(){
//     string str1, str2;
//     cin>>str1>>str2;
//     cout<<lcs(str1, str2);
//     return 0;
// }
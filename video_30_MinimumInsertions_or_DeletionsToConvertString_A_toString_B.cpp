// #include<ostream>
// #include<bits/stdc++.h>
// using namespace std;

// int canYouMake(string &s1, string &s2){
//     // Write your code here.
//     int n = s1.size(), m = s2.size();
//     vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
//     for(int i = 0; i<=n; i++) dp[i][0] = 0;
//     for(int j = 0; j<=m; j++) dp[0][j] = 0;

//     for(int i = 1; i<=n; i++){
//         for(int j = 0; j<=m; j++){
//             if(s1[i-1] == s2[j-1])
//                 dp[i][j] = 1+dp[i-1][j-1];
//             else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
//         }
//     }
//     int len = dp[n][m];
//     return (n-len)+(m-len);
// }

// int main(){
//     string str1, str2;
//     cin>> str1>>str2;
//     cout<<canYouMake(str1, str2);
//     return 0;
// }
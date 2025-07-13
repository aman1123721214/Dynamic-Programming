// #include<iostream>
// #include<bits/stdc++.h>
// using namespace std;

/*********************************************** MEMOIZATION ************************************************************ */
// int solve(int i, int j, string &s1, string &s2, vector<vector<int>> &dp){
//     if(i<0) return j+1;
//     if(j<0) return i+1;
//     if(dp[i][j] != -1) return dp[i][j];

//     if(s1[i] == s2[j]) return dp[i][j] = solve(i-1, j-1, s1, s2, dp);
//     else return dp[i][j] = 1+min(solve(i-1, j, s1, s2, dp), min(solve(i, j-1, s1, s2, dp), solve(i-1, j-1, s1, s2, dp)));
// }
// int editDistance(string str1, string str2){
//     //write you code here
//     int n = str1.size(), m = str2.size();
//     vector<vector<int>> dp(n, vector<int> (m, -1));
//     return solve(n-1, m-1, str1, str2, dp);
// }

/*********************************************** TABULATION ************************************************************ */
// int editDistance(string s1, string s2){
//     //write you code here
//     int n = s1.size(), m = s2.size();
//     vector<vector<int>> dp(n+1, vector<int> (m+1, 0));

//     for(int i = 0; i<=n; i++) dp[i][0] = i;
//     for(int j = 0; j<=m; j++) dp[0][j] = j;

//     for(int i = 1; i<=n; i++){
//         for(int j = 1; j<=m; j++){
//             if(s1[i-1] == s2[j-1]) 
//                 dp[i][j] = dp[i-1][j-1];
//             else
//             dp[i][j] = 1+min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1]));
//         }
//     }return dp[n][m];
// }

/*********************************************** MAX SPACE OPT ******************************************************* */
// int editDistance(string s1, string s2){
//     //write you code here
//     int n = s1.size(), m = s2.size();
//     vector<int> prev(m+1, 0), curr(m+1, 0);

//     for(int i = 0; i<=m; i++) prev[i] = i;

//     for(int i = 1; i<=n; i++){
//         curr[0] = i;
//         for(int j = 1; j<=m; j++){
//             if(s1[i-1] == s2[j-1]) 
//                 curr[j] = prev[j-1];
//             else
//             curr[j] = 1+min(prev[j], min(curr[j-1], prev[j-1]));
//         }prev = curr;
//     }return prev[m];
// }

/*********************************************** MAIN **************************************************************** */
// int main(){
//     string s1, s2;
//     cin>>s1>>s2;
//     cout<<editDistance(s1, s2);
//     return 0;
// }
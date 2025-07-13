// #include<iostream>
// #include<bits/stdc++.h>
// using namespace std;

/******************************************* MEMOIZATION **************************************************** */
// int solve(int i, int j, string &s1, string &s2, vector<vector<int>> &dp){
//     if(j<0) return 1;
//     if(i<0) return 0;
//     if(dp[i][j] != -1) return dp[i][j];

//     if(s1[i] == s2[j]) return dp[i][j] = solve(i-1, j-1, s1, s2, dp)+solve(i-1, j, s1, s2, dp);
//     return dp[i][j] = solve(i-1, j, s1, s2, dp);
// }
// int distinctSubsequences(string &str, string &sub){
// 	// Write your code here.
//     int n = str.size(), m = sub.size();
//     vector<vector<int>> dp(n, vector<int> (m, -1));
//     return solve(n-1, m-1, str, sub, dp);
// }

/******************************************* TABULATION ***************************************************** */
// int distinctSubsequences(string &s, string &t){
// 	// Write your code here.
//     int n = s.size(), m = t.size();
//     vector<vector<double>> dp(n+1, vector<double> (m+1, 0));

//     for(int i = 0; i<=n; i++) dp[i][0] = 1;

//     for(int i = 1; i<=n; i++){
//         for(int j = 1; j<=m; j++){
//             if(s[i-1] == t[j-1])
//                 dp[i][j] = dp[i-1][j-1]+dp[i-1][j];
//             else dp[i][j] = dp[i-1][j];
//         }
//     }
//     // for(int i = 0; i<=n; i++){
//     //     for(int j = 0; j<=m; j++) cout<<" "<<dp[i][j];
//     //     cout<<endl;
//     // }
//     return (int)dp[n][m]; 
// }

/******************************************* MAX SPACE OPT ************************************************* */
// int distinctSubsequences(string &s, string &t){
// 	// Write your code here.
//     int n = s.size(), m = t.size();
//     vector<double> prev(m+1, 0), curr(m+1, 0);
//     prev[0] = curr[0] = 1;

//     for(int i = 1; i<=n; i++){
//         for(int j = 0; j<=m; j++){
//             if(s[i-1] == t[j-1])
//                 curr[j] = prev[j-1]+prev[j];
//             else curr[j] = prev[j];
//         }prev = curr;
//     }return (int)prev[m];
// }

/******************************************** 1D SPACE SOLN. ********************************************** */
// int distinctSubsequences(string &s, string &t){
	// int n = s.size(), m = t.size();
    // vector<long long> dp(m+1, 0);
    // dp[0] = 1;

    // for(int i = 1; i<=n; i++){
    //     for(int j = m; j>=1; j--){
    //         if(s[i-1] == t[j-1])
    //             dp[j] = (dp[j-1]+dp[j])%1000000007;
    //         else dp[j] = dp[j]%1000000007;
    //     }
    // }return (int)dp[m];
// }

/********************************************* MAIN ******************************************************* */
// int main(){
//     string s1, s2;
//     cin>>s1>>s2;
//     cout<<distinctSubsequences(s1, s2);
//     return 0;
// }


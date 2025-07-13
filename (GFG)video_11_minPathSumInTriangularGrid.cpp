// #include<iostream>
// #include<bits/stdc++.h>
// using namespace std;

/**************************************** MEMOIZATION ********************************************* */
// int solve(int row, int col, vector<vector<int>> &tr, vector<vector<int>> &dp, int n){
//     if(row == n-1) return dp[n-1][col] = tr[n-1][col];
//     if(dp[row][col] != -1) return dp[row][col];

//     int down = tr[row][col]+solve(row+1, col, tr, dp, n);
//     int diag = tr[row][col]+solve(row+1, col+1, tr, dp, n);

//     return dp[row][col] = min(down, diag);
// }
// int minimizeSum(int n, vector<vector<int>>& tr) {
//     // Code here
//     vector<vector<int>> dp(n, vector<int> (n, -1));
//     return solve(0, 0, tr, dp, n);
// }
/*********************************** TABULATION *****************************************************/
// int minimizeSum(int n, vector<vector<int>>& triangle) {
//     // Code here
//     vector<vector<int>> dp(n, vector<int> (n, 0));
//     dp[n-1] = triangle[n-1];

//     for(int row = n-2; row>=0; row--){
//         for(int col = row; col>=0; col--){
//             int up = triangle[row][col]+dp[row+1][col];
//             int diag = triangle[row][col]+dp[row+1][col+1];
//             dp[row][col] = min(up, diag);
//         }
//     }return dp[0][0];
// }

/************************************ MAX SPACE OPT *********************************************** */

// int minimizeSum(int n, vector<vector<int>>& tr) {
//     // Code here
//     vector<int> prev(n, 0), curr(n, 0);
//     prev = tr[n-1];

//     for(int row = n-2; row>=0; row--){
//         for(int col = row; col>=0; col--){
//             int up = tr[row][col]+prev[col];
//             int diag = tr[row][col]+prev[col+1];

//             curr[col] = min(up, diag);
//         }prev = curr;
//     }return prev[0];
// }

/************************************ MAIN ******************************************************* */
// int main(){
//     int n;
//     cin>>n; 
//     vector<vector<int>> tr(n, vector<int> (n, 0));
//     for(int i = 0; i<n; i++){
//         for(int j = i; j<n; j++){
//             cin>>tr[i][j];
//         }
//     }
//     cout<<minimizeSum(n, tr);
// }

















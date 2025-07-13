// #include<iostream>
// #include<bits/stdc++.h>
// using namespace std;

/*********************************************** MEMOIZATION ************************************************************** */
// int solve(int row, int col, vector<vector<int>>& triangle, int n, vector<vector<int>>& dp){
//     if(row == n-1) return dp[n-1][col]=triangle[n-1][col];
//     if(dp[row][col] != -1) return dp[row][col];

//     int d = triangle[row][col]+solve(row+1, col, triangle, n, dp);
//     int dg = triangle[row][col]+solve(row+1, col+1, triangle, n, dp);

//     return dp[row][col]=min(d, dg);    
// }
// int minimumPathSum(vector<vector<int>>& triangle, int n){
// 	// Write your code here.
//     vector<vector<int>> dp(n, vector<int>(n, -1));
//     return solve(0, 0, triangle, n, dp);
// }

/************************************************* TABULATION ************************************************************ */
// int minimumPathSum(vector<vector<int>>& triangle, int n){
// 	// Write your code here.
//     vector<vector<int>> dp(n, vector<int>(n, -1));
//     dp[n-1] = traingle[n-1];

//     for(int i = n-2; i>=0; i--){
//         for(int j = i; j>=0; j--){
//             int d = triangle[i][j]+dp[i+1][j];
//             int dg = triangle[i][j]+dp[i+1][j+1];
//             dp[i][j] = min(d, dg);
//         }
//     }
//     return dp[0][0];
// }

/************************************************** MAX SPACE OPTIMIZATION ********************************************** */
// int minimumPathSum(vector<vector<int>>& triangle, int n){
// 	// Write your code here.
//     vector<int> prev(n, 0);
//     vector<int> curr(n, 0);
//     prev = triangle[n-1];

//     for(int row = n-2; row>=0; row--){
//         for(int col = row; col>=0; col--){
//             int d = triangle[row][col]+prev[col];
//             int dg = triangle[row][col]+prev[col+1];
//             curr[col] = min(d, dg);
//         }
//         prev = curr;
//     }
//     return prev[0];
// }

/************************************************* MAIN ***************************************************************** */
// int main(){
//     int n;
//     cout<<"enter n: ";
//     cin>>n;
//     vector<vector<int>> triangle(n)
//     cout<<"enter elements in triangle: ";
//     for(int i = 0; i<n; i++){
//         for(int j = 0; j<=i; j++){
//             int element;
//             cin>>element;
//             triangle[i].push_back(element);
//         }
//     }
//     cout<<minimumPathSum(triangle, n);
// }
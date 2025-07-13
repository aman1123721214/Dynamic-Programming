// #include<iostream>
// #include<bits/stdc++.h>
// using namespace std;
/**************************************************** MEMOIZATION ******************************************************** */

// int solve(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &dp){
//     if(row == 0 && col == 0) return grid[row][col];
//     if(row<0 || col<0) return 1e9;
//     if(dp[row][col] != -1) return dp[row][col];

//     int up = grid[row][col]+solve(row-1, col, grid, dp);
//     int left = grid[row][col]+solve(row, col-1, grid, dp);

//     return dp[row][col] = min(up, left);
// }
// int minSumPath(vector<vector<int>> &grid) {
//     // Write your code here.
//     int row = grid.size();
//     int col = grid[0].size();
//     vector<vector<int>> dp(row, vector<int> (col, -1));
//     //dp[0][0] = 1;
//     return solve(row-1, col-1, grid, dp);
// }
/*************************************************** TABULATION ********************************************************* */
// int minSumPath(vector<vector<int>> &matrix) {
//     // Write your code here.
//     int n = matrix.size();
//     int m = matrix[0].size();
//     vector<vector<int>> dp(n, vector<int>(m, 0)); // Initialize a DP table to store minimum path sums

//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < m; j++) {
//             if (i == 0 && j == 0)
//                 dp[i][j] = matrix[i][j]; 
//             else {
//                 int up = matrix[i][j];
//                 if (i > 0) up += dp[i - 1][j]; 
//                 else up += 1e9; 

//                 int left = matrix[i][j];
//                 if (j > 0) left += dp[i][j - 1]; 
//                 else left += 1e9; 

//                 dp[i][j] = min(up, left);
//             }
//         }
//     }return dp[n-1][m-1];
// }

/************************************************* MAIN *************************************************************** */
// int main(){
//     int row, col, elements;
//     cout<<"enter rows and col: ";
//     cin>>row>>col;
//     vector<vector<int>> grid(row, vector<int> (col));
//     cout<<"enter elements in the grid: ";
//     for(int i = 0; i<row; i++){
//         for(int j = 0; j<col; j++){
//             cin>>grid[i][j];
//         }
//     }
//     cout<<"min path sum is: "<<minSumPath(grid);
//     return 0;
// }
// #include<iostream>
// #include<bits/stdc++.h>
// using namespace std;
/******************************************* RECURSIVE SOLN.****************************************** */
// int paths(int row, int col){
//     if(row == 0 && col == 0) return 1;
//     if(row<0 || col<0) return 0;
//     int up = paths(row-1, col);
//     int left = paths(row, col-1);
//     return up+left;
// }
// TC = 2^(ROW*COL)                   S.C = O(ROW+COL) i.e recursion pathlength

/******************************************* MEMOIZATION ********************************************* */
// int solve(int row, int col, vector<vector<int>> &dp){
//     if(row == 0 && col == 0) return dp[row][col] = 1;
//     if(row<0 || col<0) return 0;
//     if(dp[row][col] != -1) return dp[row][col];

//     int up = solve(row-1, col, dp);
//     int left = solve(row, col-1, dp);

//     dp[row][col] = up+left;
// }

// int paths(int row, int col){
//     vector<vector<int>> dp(row, vector<int> (col, -1));
//     return solve(row-1, col-1, dp);
// }

//TC = O(ROW*COL)                   S.C = O(ROW+COL)+O(ROW*COL)

/******************************************* TABULATION ********************************************* */

// int paths(int row, int col){
//     vector<vector<int>> dp(row, vector<int> (col, -1));
//     dp[0][0] = 1;
    
//     for(int i = 1; i<row; i++){
//             for(int j = 1; j<col; j++){
//                 int up = dp[i-1][j];
//                 int left = dp[i][j-1];
//                 dp[i][j] = up+left;
//             } 
//     }
//     return abs(dp[row-1][col-1]);
// }
// T.C = O(ROW*COL)                 S.C = O(ROW*COL)

/******************************************** MAX SPACE OPTIMIZATION ********************************** */

// int paths(int row, int col){
//     vector<int> prev(col, 0);
//     for(int i = 0; i<row; i++){
//         vector<int> curr(col, 0);
//         for(int j = 0; j<col; j++){
//             if(i == 0 && j == 0) curr[j] = 1;
//             else{
//                 int up = 0;
//                 int left = 0;
//                 if(i>0) up = prev[j];
//                 if(j>0) left = curr[j-1];
//                 curr[j] = up+left;
//             }
//         }
//         prev = curr;
//     }
//     return prev[col-1];
// }

// T.C = O(ROW*COL)                 S.C = O(COL)

/******************************************** MAIN ************************************************** */
// int main(){
//     int row, col;
//     cout<<"enter row and col: "<<endl;
//     cin>>row;
//     cin>>col;
//     cout<<"total paths found = "<<paths(row-1, col-1);
// }
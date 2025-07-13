  // #include<iostream>
// #include<bits/stdc++.h>
// using namespace std;
/*************************************************** RECURSION ***************************************************** */
// int uniquePath(int row, int col, vector<vector<int>> &maze){
//     if(row == 0 && col == 0) return 1;
//     if(row<0 || col<0 || maze[row][col] == -1) return 0;
//     int up = uniquePath(row-1, col, maze);
//     int left = uniquePath(row, col-1, maze);
//     return (up+left)%1000000007;
// }
/**************************************************** MEMOIZATION *************************************************** */
// int solve(int row, int col, vector< vector< int> > &maze, vector<vector<int>> &dp){
//     if(row == 0 && col == 0) return dp[row][col] = 1;
//     if(row<0 || col<0 || maze[row][col] == -1) return 0;
//     if(dp[row][col] != -1) return dp[row][col];

//     int up = solve(row-1, col, maze, dp);
//     int left = solve(row, col-1, maze, dp);
//     return dp[row][col] = up+left;
// }

// int mazeObstacles(int row, int col, vector< vector< int> > &maze) {
//     // Write your code here
//     vector<vector<int>> dp(row, vector<int> (col, -1));
//     return solve(row-1, col-1, maze, dp)%1000000007;
// }

/**************************************************** TABULATION **************************************************** */
// int mazeObstacles(int row, int col, vector< vector< int> > &maze) {
//     // Write your code here
//     int dp[row][col];

//     for(int i = 0; i<row; i++){
//         for(int j = 0; j<col; j++){
//             if(maze[i][j] == -1) dp[i][j] = 0;
//             else if(i == 0 && j == 0) dp[i][j] = 1;
//             else{
//                 int up = 0, left = 0;
//                 if(i>0)up = dp[i-1][j];
//                 if(j>0)left = dp[i][j-1];
//                 dp[i][j] = (up+left)% 1000000007;
//             }
//         }
//     }
//     return dp[row-1][col-1];
// }

/************************************************** MAX SPACE OPTIMIZATION **************************************** */
// int mazeObstacles(int row, int col, vector< vector< int> > &maze) {
//     // Write your code here
//     vector<int> prev(col, 0);

//     for(int i = 0; i<row; i++){
//         vector<int> curr(col, 0);
//         for(int j = 0; j<col; j++){
//             if(maze[i][j] == -1) curr[j] = 0;
//             else if(i == 0 && j == 0) curr[j] = 1;
//             else{
//                 int up = 0, left = 0;
//                 if(i>0)up = prev[j];
//                 if(j>0)left = curr[j-1];
//                 curr[j] = (up+left)% 1000000007;
//             }
//         }
//         prev = curr;
//     }
//     return prev[col-1];
// }

/************************************************* MAIN ********************************************************* */
// int main(){
//     int row,col;
//     cout<<"enter row and col: ";
//     cin>>row>>col;
    
//     vector<vector<int>> maze(row, vector<int> (col));
//     cout<<"enter elements in the maze: ";
//     for(int i = 0; i<row; i++){
//         for(int j = 0; j<col; j++){
//             cin>>maze[i][j];
//         }
//     }

//     cout<<"number of unique paths: "<<mazeObstacles(row, col, maze);
//     return 0;
// }
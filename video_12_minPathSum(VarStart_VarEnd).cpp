// #include<iostream>
// #include<bits/stdc++.h>
// using namespace std;

/************************************************** MEMOIZATION ************************************************ */
// int solve(int row, int col, vector<vector<int>> &mat, vector<vector<int>> &dp){
//     int m = mat[0].size();
    
//     if(col>=m || col<0) return -1e9;
//     if(row == 0) return dp[0][col]=mat[0][col];
//     if(dp[row][col] != -1) return dp[row][col];

//     int d = mat[row][col]+solve(row-1, col, mat, dp);
//     int ldg = mat[row][col]+solve(row-1, col-1, mat, dp);
//     int rdg = mat[row][col]+solve(row-1, col+1, mat, dp);

//     return dp[row][col] = max(d, max(ldg, rdg));

// }
// int getMaxPathSum(vector<vector<int>> &mat)
// {
//     //  Write your code here.
//     int col = mat[0].size(), maxi = -1e9, row = mat.size();
//     vector<vector<int>> dp(row, vector<int> (col, -1));
//     for(int i = 0; i<col; i++){
//         int ans = solve(row-1, i, mat, dp);
//         maxi = max(maxi, ans);
//     }
//     return maxi;
// }

/************************************************ TABULATION ************************************************** */
// int getMaxPathSum(vector<vector<int>> &mat)
// {
//     //  Write your code here.
//     int row = mat.size(), col = mat[0].size();
//     vector<vector<int>> dp(row, vector<int>(col, 0));
//     dp[0] = mat[0];

//     for(int i = 1; i<row; i++){
//         for(int j = 0; j<col; j++){
//             int up = mat[i][j]+dp[i-1][j];
            
//             int ldg = mat[i][j];
//             if(j>0) ldg+=dp[i-1][j-1];
//             else ldg = -1e9;

//             int rdg = mat[i][j];
//             if(j<col-1) rdg+=dp[i-1][j+1];
//             else rdg = -1e9;

//             dp[i][j] = max(up, max(ldg, rdg));
//         }
//     }

//     int maxi = INT_MIN;
//     for(int i = 0; i<col; i++){
//         maxi = max(maxi, dp[row-1][i]);
//     }
//     return maxi;
// }

/*************************************************** MAIN ******************************************************* */
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
    
//     cout<<"max path sum: "<<getMaxPathSum(maze);
//     return 0;
// }
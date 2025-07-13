// #include<iostream>
// #include<bits/stdc++.h>
// using namespace std;
// int mod=1000000007;
    
    // int fun(int i,int j,int &n,int &m,vector<vector<int>> &grid,vector<vector<int>> &dp){
    //     if(i==n-1 && j==m-1)
    //         return 1;
    //     if(dp[i][j]!=-1)
    //         return dp[i][j];
        
    //     int r=0;
    //     int d=0;
        
    //     if(i>=0 && i<n && (j+1)>=0 && (j+1)<m && grid[i][j+1])
    //         r=fun(i,j+1,n,m,grid,dp);
        
    //     if((i+1)>=0 && (i+1)<n && j>=0 && j<m && grid[i+1][j])
    //         d=fun(i+1,j,n,m,grid,dp);
        
    //     return dp[i][j]=(r+d)%mode;
    // }
    
    
    // int uniquePaths(int n, int m, vector<vector<int>> &grid) {
    //     // code here
    //     if(grid[0][0]==0 || grid[n-1][m-1]==0)
    //         return 0;
    //     vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    //     return fun(0,0,n,m,grid,dp);
    // }

/******************************************** TABULATION ********************************************** */
// int uniquePaths(int n, int m, vector<vector<int>> &grid) {
//         // code here
//         if(grid[n-1][m-1] == 0 || grid[0][0] == 0) return 0;
//         vector<vector<int>> dp(n, vector<int> (m, 0));    

//         for(int row = 0; row<n; row++){
//             for(int col = 0; col<m; col++){
//                 if(row == 0 && col == 0) dp[0][0] = 1;
//                 else {
//                 int up = 0, left = 0;
//                 if(row>0 && grid[row-1][col]) up = dp[row-1][col];
//                 if(col>=0 && grid[row][col-1]) left = dp[row][col-1];

//                 dp[row][col] = (up+left)%mod;
//                 }
//             }
//         }
//         return dp[n-1][m-1];
// }

/*********************************************** MAX SPACE OPT**************************************** */
// int uniquePaths(int n, int m, vector<vector<int>> &grid) {
//         // code here
//         if(grid[n-1][m-1] == 0 || grid[0][0] == 0) return 0;
//         vector<int> prev(m, 0), curr(m, 0);  

//         for(int row = 0; row<n; row++){
//             for(int col = 0; col<m; col++){
//                 if(row == 0 && col == 0) curr[0] = 1;
//                 else {
//                 int up = 0, left = 0;
//                 if(row>0 && grid[row-1][col]) up = prev[col];
//                 if(col>=0 && grid[row][col-1]) left = curr[col-1];

//                 curr[col] = (up+left)%mod;
//                 }
//             }prev = curr;
//         }
//         return prev[m-1];
// }

/************************************************ MAIN *********************************************** */
// int main(){
//     int n, m;
//     cin>>n>>m;
//     vector<vector<int>> mat(n, vector<int> (m, 0));
//     for(int i = 0; i<n; i++){
//         for(int j = 0; j<m; j++){
//             cin>>mat[i][j];
//         }
//     }
//     cout<<uniquePaths(n, m, mat);
//     return 0;
// }
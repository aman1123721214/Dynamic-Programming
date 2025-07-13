#include<bits/stdc++.h>
using namespace std;

class Solution {
  private: int mod = 1e9+7;
  int solve(int row, int col, vector<vector<int>>& grid, vector<vector<int>> &dp){
    if(row == 0 && col == 0) return 1;
    if(dp[row][col] != -1) return dp[row][col];
    
    int up = 0, left = 0;
    if(row-1>=0 && grid[row-1][col] == 0)
        up = solve(row-1, col, grid, dp);
    if(col-1>=0 && grid[row][col-1] == 0)
        left = solve(row, col-1, grid, dp);
    
    return dp[row][col] = (up+left)%mod;
  }
  public:
    int totalWays(int n, int m, vector<vector<int>>& grid) {
        // Code here
        vector<int> prev(n, 0);

        for(int i = 0; i<m; i++){
            vector<int> curr(n, 0);
            for(int j = 0; j<n; j++){
                if(grid[i][j] == 1) curr[j] = 0;
                else if(i == 0 && j == 0) curr[j] = 1;
                else{
                    int up = 0, left = 0;
                    if(i>0)up = prev[j];
                    if(j>0)left = curr[j-1];
                    curr[j] = (up+left)% 1000000007;
                }
            }
            prev = curr;
        }
        return prev[n-1];
    }
//   private: int mod = 1e9+7;
//   int solve(int row, int col, vector<vector<int>>& grid, vector<vector<int>> &dp){
//     if(row == 0 && col == 0) return 1;
//     if(dp[row][col] != -1) return dp[row][col];
    
//     int up = 0, left = 0;
//     if(row-1>=0 && grid[row-1][col] == 0)
//         up = solve(row-1, col, grid, dp);
//     if(col-1>=0 && grid[row][col-1] == 0)
//         left = solve(row, col-1, grid, dp);
    
//     return dp[row][col] = (up+left)%mod;
//   }
//   public:
//     int totalWays(int n, int m, vector<vector<int>>& grid) {
//         // Code here
//         if(grid[0][0] == 0 || grid[m-1][n-1] == 0) return 0;
//         vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
//         return solve(m-1, n-1, grid, dp)%mod;
//     }
};

int main(){
    int m, n;
    cin>>m>>n;

    vector<vector<int>> grid(m, vector<int>(n, 0));
    for(int i = 0; i<m; i++){
        for(int j = 0;j<n; j++)
            cin>>grid[i][j];
    }

    Solution obj;
    cout<<obj.totalWays(n, m, grid);
}
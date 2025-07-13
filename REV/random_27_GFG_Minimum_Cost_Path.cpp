#include<bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7;

class Solution {
private:
    bool check(int row, int col, int n) {
        return row >= 0 && row < n && col >= 0 && col < n;
    }

    int solve(int row, int col,  
    vector<vector<int>>& grid, vector<vector<int>> &dp) {
        if (row == 0 && col == 0) return dp[row][col] = grid[0][0];
        if(dp[row][col] != -1) return dp[row][col];


        int up = grid[row][col];
        if(row>0) up+=solve(row-1, col, grid, dp);
        else up = 1e9;

        int left = grid[row][col];
        if(col>0) left+=solve(row, col-1, grid, dp);
        else left = 1e9;

        return dp[row][col] = min(up, left);
    }

public:
    int minimumCostPath(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        vector<vector<bool>> vis(n, vector<bool>(n, 0));
        vis[0][0] = 1;
        return solve(n-1, n-1, grid, dp) % mod;
    }
//     bool check(int row, int col, int n) {
//         return row >= 0 && row < n && col >= 0 && col < n;
//     }

//     int solve(int row, int col, int n, vector<vector<bool>> &vis, vector<vector<int>>& grid, vector<vector<int>>& dp) {
//         if (row == n - 1 && col == n - 1) return grid[n - 1][n - 1];
//         vis[row][col] = 1;
//         if (dp[row][col] != -1) return dp[row][col];

//         int delRow[] = {-1, 1, 0, 0};
//         int delCol[] = {0, 0, -1, 1};

//         int ans = INT_MAX;
//         for (int i = 0; i < 4; i++) {
//             int nrow = row + delRow[i];
//             int ncol = col + delCol[i];

//             if (check(nrow, ncol, n) && !vis[nrow][ncol]) {
//                 int cost = (grid[row][col] + solve(nrow, ncol, n, vis, grid, dp)) % mod;
//                 ans = min(ans, cost);
//             }
//         }
        
//         vis[row][col] = 0;
//         return dp[row][col] = ans % mod;
//     }

// public:
//     int minimumCostPath(vector<vector<int>>& grid) {
//         int n = grid.size();
//         vector<vector<int>> dp(n, vector<int>(n, -1));
//         vector<vector<bool>> vis(n, vector<bool>(n, 0));
//         vis[0][0] = 1;
//         return solve(0, 0, n, vis, grid, dp) % mod;
//     }
};

int main(){
    int n; cin>>n;
    vector<vector<int>> grid(n, vector<int> (n));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++)
            cin>>grid[i][j];
    }

    Solution obj;
    cout<<obj.minimumCostPath(grid);

    return 0;
}
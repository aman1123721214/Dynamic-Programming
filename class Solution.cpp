#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:

    int solve(int row, int col, int n, int m, vector<vector<int>>& grid,
     vector<vector<int>>& dp, vector<vector<bool>>& vis){
        if(row==n && col==m)
            return grid[row][col];

        if(dp[row][col]!=-1) return dp[row][col];
        vis[row][col] = 1;
        int drow[] = {1, -1, 0, 0};
        int dcol[] = {0, 0, 1, -1};
        int ans = INT_MAX;

        for(int i = 0; i<4; i++){
            int nrow = row+drow[i];
            int ncol = col+dcol[i];

            if(nrow>=0 && nrow<=n && ncol>=0 && ncol<=m){
                if(!vis[nrow][ncol]){
                    ans = min(ans, grid[row][col]+solve(nrow, ncol, n, m, grid, dp, vis));
                }
            }
        }
        vis[row][col] = 0;
        return dp[row][col] = ans;
     }
    //Function to return the minimum cost to react at bottom
	//right cell from top left cell
    int minimumCostPath(vector<vector<int>>& grid) {
        // Code here
        int row = grid.size();
        int col = grid[0].size();

        vector<vector<bool>> vis(row, vector<bool> (col, 0));
        vector<vector<int>> dp(row, vector<int> (col, -1));

        return solve(0, 0, row-1, col-1, grid, dp, vis);
    }
};

int main(){
    int n; cin>>n;
    vector<vector<int>> grid(n, vector<int> (n, 0));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++)
            cin>>grid[i][j];
    }

    Solution obj;
    cout<<obj.minimumCostPath(grid);
}
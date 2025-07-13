#include<bits/stdc++.h>
using namespace std;

class Solution{
  private:int row, col;
    int solve(int i, int j, vector<vector<int>> &points, vector<vector<int>> &dp){
        if(i>=row || j>=col) return 1e9;
        if(i == row-1 && j == col-1) 
            return (points[i][j]<=0) ? (1-points[i][j]) : 1 ;
        
        if(dp[i][j] != -1) return dp[i][j]; 

        int up = solve(i+1, j, points, dp);
        int left = solve(i, j+1, points, dp);

        int ans = min(up, left)-points[i][j];
        return dp[i][j] = (ans<=0) ? 1 : ans ;
    }
  public:
    int minPoints(int m, int n, vector<vector<int>> points){
        vector<vector<int>> dp(m, vector<int>(n, -1));
        row = m, col = n;
        return solve(0, 0, points, dp);
    }
};

int main(){
    int n, m;
    cin>>n>>m;

    vector<vector<int>> points(m, vector<int>(n));
    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++)
            cin>>points[i][j];        
    }

    Solution obj;
    cout<<obj.minPoints(m, n, points);

    return 0;
}
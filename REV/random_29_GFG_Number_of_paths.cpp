#include<bits/stdc++.h>
using namespace std;

class Solution {
  private:
    int solve(int i, int j, vector<vector<int>> &dp){
        if(i == 0 && j == 0) return 1;
        if(dp[i][j] != -1) return dp[i][j];

        int up = 0;
        if(i-1>=0) up = solve(i-1, j, dp);

        int left = 0;
        if(j-1>=0) left = solve(i, j-1, dp);

        return dp[i][j] = up+left;
    }
  public:
    int numberOfPaths(int m, int n) {
        // Code Here
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(m-1, n-1, dp);
    }
};
#include<bits/stdc++.h>
using namespace std;

class Solution {
  private:
    int solve(int i, int j, vector<vector<int>> &dp, string &s1, string &s2){
        if(i<0 || j<0) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        if(s1[i] == s2[j])  
            return dp[i][j] = 1+solve(i-1, j-1, dp, s1, s2);
        else return dp[i][j] = max(solve(i-1, j, dp,s1, s2), solve(i, j-1, dp, s1, s2));
    }
  public:
    int shortestUnSub(string S, string T) {
        // code here
        int n = S.size(), m = T.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));

        int ans = solve(n-1, m-1, dp, S, T);
        return (n>m)?n-ans:m-ans;
    }
};
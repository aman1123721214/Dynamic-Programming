#include<bits/stdc++.h>
using namespace std;

class Solution {
  private:
    int solve(int i, int j, string str,
    vector<vector<int>> &dp){
        if(i>j) return 0;
        if(i == j) return 1;
        
        if(dp[i][j] != -1) return dp[i][j];

        if(str[i] == str[j])
            return dp[i][j] = 1+solve(i+1, j, str, dp)+solve(i, j-1, str, dp);
        else return dp[i][j] = solve(i+1, j, str, dp)+solve(i, j-1, str, dp)-solve(i+1, j-1, str, dp);
    }
  public:
    /*You are required to complete below method */
    int countPS(string &s) {
        // Your code here
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(0, n-1, s, dp);
    }
};

int main(){
    string s;
    cin>>s;
    Solution obj;
    cout<<obj.countPS(s);

    return 0;
}
#include<bits/stdc++.h>
using namespace std;

class Solution{
  private:
    int n, m;

    bool solve(int i, int j, string &s1, string &s2, string &s3,
    vector<vector<int>> &dp){
        if(i == n && j == m) return 1;

        if(dp[i][j] != -1) return dp[i][j];

        bool first = 0, sec = 0;
        int k = i+j;

        if(s1[i] == s3[k])
            first = solve(i+1, k, s1, s2, s3, dp);
        if(s2[j] == s3[k])
            sec = solve(i, k+1, s1, s2, s3, dp);
        
        return dp[i][j] = first || sec;
    }
  public:
    bool isInterleave(string &s1, string &s2, string &s3){
        n = s1.size(); m = s2.size();
        vector<vector<int>> dp(n+1, vector<int> (m+1, -1));
        return solve(0, 0, s1, s2, s3, dp);
    }
};

int main(){
    string s1, s2, s3;
    cin>>s1>>s2>>s3;

    Solution obj;
    cout<<obj.isInterleave(s1, s2, s3);

    return 0;
}
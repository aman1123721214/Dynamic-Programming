#include<bits/stdc++.h>
using namespace std;

class Solution {
  private:int p, q, r;
  
    int solve(int i, int j, int k, string &s1, string &s2, string &s3,
    vector<vector<vector<int>>> &dp){
        if(i<0 || j<0 || k<0) return 0;
        if(dp[i][j][k] != -1) return dp[i][j][k];
        
        if(s1[i] == s2[j]){
            if(s2[j] == s3[k])
                return dp[i][j][k] = 1+solve(i-1, j-1, k-1, s1, s2, s3, dp);
        }
        
        return dp[i][j][k] = max(solve(i, j, k-1, s1, s2, s3, dp),
        max(solve(i, j-1, k, s1, s2, s3, dp), solve(i-1, j, k, s1, s2, s3, dp)));
    }
  public:

    int LCSof3(string& s1, string& s2, string& s3) {
        // your code here
        p = s1.size();
        q = s2.size();
        r = s3.size();
        
        vector<vector<vector<int>>> dp(p, vector<vector<int>>(q, vector<int>(r, -1)));
        return solve(p-1, q-1, r-1, s1, s2, s3, dp);
    }
};

int main(){
    string s1, s2, s3;
    cin>>s1>>s2>>s3;

    Solution obj;
    cout<<obj.LCSof3(s1, s2, s3);

    return 0;
}
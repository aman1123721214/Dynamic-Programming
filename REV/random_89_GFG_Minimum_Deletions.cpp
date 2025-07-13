#include<bits/stdc++.h>
using namespace std;

class Solution{
  private:
    int solve(int i, int j, string &s1, string &s2, vector<vector<int>> &dp){
        if(i<0 || j<0) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        int ans = 0;
        if(s1[i] == s2[j])
            ans = 1+solve(i-1, j-1, s1, s2, dp);
        else ans = max(solve(i, j-1, s1, s2, dp),
                        solve(i-1, j, s1, s2, dp));
        
        return dp[i][j] = ans;
    }
  public:
    int minimumNumberOfDeletions(string S) { 
        // code here
        int n = S.size();
        string str = S;
        vector<vector<int>> dp(n, vector<int>(n, -1));

        reverse(str.begin(), str.end());
        return n-solve(n-1, n-1, S, str, dp);
    } 
};

int main(){
    string str;
    cin>>str;

    Solution obj;
    cout<<obj.minimumNumberOfDeletions(str);

    return 0;
}
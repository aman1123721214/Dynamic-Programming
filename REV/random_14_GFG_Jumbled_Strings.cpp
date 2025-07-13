#include<bits/stdc++.h>
using namespace std;

int mod = 1e9+7;
class Solution{
  private:
    int solve(int i, int j, string &s1, string &s2,
    vector<vector<int>> &dp){
        if(j<0) return 1;
        if(i<0) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        if(s1[i] == s2[j]){
            int take = solve(i-1, j-1, s1, s2, dp);
            int nTake = solve(i-1, j, s1, s2, dp);
            return dp[i][j] = (take+nTake)%mod;
        }
        else return dp[i][j] = solve(i-1, j, s1, s2, dp)%mod;
    }
  public:
	int TotalWays(string str){
	    // Code here
        string s = "GEEKS";
        int n = str.length(), m = s.length();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(n-1, m-1, str, s, dp)%mod;
	}
};

int main(){
    string str;
    cin>>str;

    Solution obj;
    cout<<obj.TotalWays(str);

    return 0;
}
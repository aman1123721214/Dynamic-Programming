#include<bits/stdc++.h>
using namespace std;

class Solution {
  private:
  int mod = 1e9+7;

  int count = 0;
    int solve(int i, int j, bool isTrue, string &s,
    vector<vector<vector<long long>>> &dp){
        if(i>j) return 0;
        if(i == j) {
            if(isTrue) return s[i] == 'T';
            return s[i] == 'F';
        }

        if(dp[i][j][isTrue] != -1) return dp[i][j][isTrue];
        long long ans = 0;

        for(int k = i+1; k<=j-1; k+=2){
            int lt = solve(i, k-1, 1, s, dp);
            int lf = solve(i, k-1, 0, s, dp);
            int rt = solve(k+1, j, 1, s, dp);
            int rf = solve(k+1, j, 0, s, dp);

            if(s[k] == '&'){
                if(isTrue) ans = (ans + (lt*rt)%mod)%mod;
                else ans = (ans+ (lt*rf)%mod +(lf*rt)%mod +(lf*lf)%mod)%mod;
            }

            else if(s[k] == '|'){
                if(isTrue) ans = (ans + (lt*rf)%mod +(lf*rt)%mod +(lt*rt)%mod)%mod;
                else ans = (ans + (lf*rf)%mod)%mod;
            }
            else {
                if(isTrue) ans = (ans +(lf*rt)%mod + (lt*rf)%mod)%mod;
                else ans = (ans +(lf*rf)%mod + (lt*rt)%mod)%mod;
            }
        }
        return dp[i][j][isTrue] = ans;
    }
  public:
    int countWays(string s) {
        // code here
        int n = s.size();
        vector<vector<vector<long long>>> dp
        (n, vector<vector<long long>>
        (n, vector<long long>(2, -1)));
        return solve(0, n-1, 1, s, dp);
    }
};

int main(){
    string str;
    getline(cin, str);
    
    Solution obj;
    cout<<obj.countWays(str);

    return 0;
}
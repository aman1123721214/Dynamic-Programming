#include<bits/stdc++.h>
using namespace std;

class Solution{
  private:int mod = 1e9+7;
    int solve(int n, int m, vector<int> &dp){
        if(n<m) return 1;
        if(dp[n] != -1) return dp[n];

        int horizStk = solve(n-1, m, dp);
        int vertStk = solve(n-m, m, dp);

        return dp[n] = (horizStk+vertStk)%mod;
    }
  public:
    int countWays(int n, int m){
        //Code here
        vector<int> dp(n+1, -1);
        return solve(n, m, dp);
    }
};

int main(){
    int n, m;   cin>>n>>m;
    Solution obj;
    cout<<obj.countWays(n, m);

    return 0;
}
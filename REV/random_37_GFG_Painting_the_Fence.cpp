#include<bits/stdc++.h>
using namespace std;


class Solution {
  private:
  int mod = 1e9+7;
    int add(int a, int b){
        return ((a%mod) + (b%mod))%mod;
    }
    int mul(int a, int b){
        return ((a%mod) * (b%mod))%mod;
    }

    int solve(int n, int k, vector<int> &dp){
        if(n == 1) return k;
        if(n == 2) return add(k, mul(k, k-1));
        if(dp[n] != -1) return dp[n];

        int ans = add(mul(k-1, solve(n-1, k, dp)), mul(k-1, solve(n-2, k, dp)));
        return dp[n] = ans;
    }
  public:
    int countWays(int n, int k) {
        // code here
        vector<int> dp(n+1, -1);
        return solve(n, k, dp);
    }
};

int main(){
    int n, k;
    cin>>n>>k;

    Solution obj;
    cout<<obj.countWays(n, k);

    return 0;
}
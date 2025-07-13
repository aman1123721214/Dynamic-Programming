#include<bits/stdc++.h>
using namespace std;

class Solution {
  private:
  int mod = 1e9+7;
    int solve(int n, vector<int> &dp){
        if(n == 0) return 1;
        if(n == 1) return 0;

        if(dp[n] != -1) return dp[n];
        return dp[n] = ((n-1)*(solve(n-1, dp)%mod+solve(n-2, dp)%mod))%mod;
    }
  public:
    int countDer(int n) {
        //Code Here
        vector<int> dp(n+1, -1);
        return solve(n, dp);
    }
};

int main(){
    int n;
    cin>>n;
    Solution obj;
    cout<<obj.countDer(n);

    return 0;
}
#include<bits/stdc++.h>
using namespace std;

class Solution{
  private:int mod = 1e9+7;
  
    int solve(int sum, int num, int total, vector<vector<int>> &dp){
        if(!sum) return 1;
        if(num>sum) return 0;

        if(dp[sum][num] != -1) return dp[sum][num];

        int take = 0, nTake = 0;
        if(sum-num>=0) take = solve(sum-num, num, total, dp);
        if(num+1<total) nTake = solve(sum, num+1, total, dp);

        return dp[sum][num] = (take+nTake)%mod;
    }

  public:
    int countWays(int n){
        //Code here
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return solve(n, 1, n, dp);
    }
};

int main(){
    int n;  cin>>n;
    Solution obj;
    cout<<obj.countWays(n);

    return 0;
}
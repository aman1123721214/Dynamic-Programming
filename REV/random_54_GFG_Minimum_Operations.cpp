#include<bits/stdc++.h>
using namespace std;

class Solution {
  private:int N;
    int solve(int i, vector<int> &dp){
        if(i == N) return 0;
        if(i>N) return 1e9;

        if(dp[i] != -1) return dp[i];

        int dbl = 1e9, one = 1e9;
        if(i != 0 && 2*i <= N) dbl = 1+solve(2*i, dp);
        if(i+1 <= N) one = 1+solve(i+1, dp);

        return dp[i] = min(dbl, one);
    }
  public:
    int minOperation(int n) {
        // code here.
        vector<int> dp(n,1e9);
        dp[n] = 0;
        
        for(int i = n-1; i>=0; i--){
            int dbl = 1e9, one = 1e9;
            if(i != 0 && 2*i <= n) dbl = 1+dp[2*i];
            if(i+1 <= n) one = 1+dp[i+1];

            dp[i] = min(dbl, one);
        }
        return dp[0];
    }

    /*************************** memoization**************************** */
//   private:int N;
//     int solve(int i, vector<int> &dp){
//         if(i == N) return 0;
//         if(i>N) return 1e9;

//         if(dp[i] != -1) return dp[i];

//         int dbl = 1e9, one = 1e9;
//         if(i != 0 && 2*i <= N) dbl = 1+solve(2*i, dp);
//         if(i+1 <= N) one = 1+solve(i+1, dp);

//         return dp[i] = min(dbl, one);
//     }
//   public:
//     int minOperation(int n) {
//         // code here.
//         vector<int> dp(n+1, -1);
//         N = n;
//         return solve(0, dp);
//     }
};

int main(){
    int n; cin>>n;
    Solution obj;
    cout<<obj.minOperation(n);

    return 0;
}
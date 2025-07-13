#include<bits/stdc++.h>
using namespace std;

class Solution {
  private:int mod = 1e9+7;
    int solve(int n, vector<int> &dp){
        if(n<=2) return 1;
        if(dp[n] != -1) return dp[n];

        return dp[n] = (solve(n-2, dp)%mod+solve(n-3, dp)%mod)%mod;
    }
  public:
    int padovanSequence(int n) {
        // code here.
        vector<int> dp(n+1, 0);
        dp[0] = dp[1] = dp[2] = 1;
        
        for(int i = 3; i<=n; i++){
            dp[i] = (dp[i-2]%mod + dp[i-3]%mod)%mod;
        }
        return dp[n];
    }
    
    /************************ TABULATION ************************ */
    // int padovanSequence(int n) {
    //     // code here.
    //     vector<int> dp(n+1, 0);
    //     dp[0] = dp[1] = dp[2] = 1;
        
    //     for(int i = 3; i<=n; i++){
    //         dp[i] = (dp[i-2]%mod + dp[i-3]%mod)%mod;
    //     }
    //     return dp[n];
    // }
    /****************** MEMOIZATION ************************** */
//   private:int mod = 1e9+7;
//     int solve(int n, vector<int> &dp){
//         if(n<=2) return 1;
//         if(dp[n] != -1) return dp[n];

//         return dp[n] = (solve(n-2, dp)%mod+solve(n-3, dp)%mod)%mod;
//     }
//   public:
//     int padovanSequence(int n) {
//         // code here.
//         vector<int> dp(n+1, -1);
//         return solve(n, dp)%mod;
//     }
};

int main(){
    int n; cin>>n;
    Solution obj;
    cout<<obj.padovanSequence(n);

    return 0;
}
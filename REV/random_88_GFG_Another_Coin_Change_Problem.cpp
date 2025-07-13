#include<bits/stdc++.h>
using namespace std;


class Solution {
  public:
    bool makeChanges(int N, int K, int target, vector<int> &coins) {
        vector<vector<vector<bool>>> dp(N + 1, vector<vector<bool>>(target + 1, vector<bool>(K + 1, false)));

        // Base case: sum = 0 and k = 0 is always true
        for (int i = 0; i <= N; ++i) {
            dp[i][0][0] = true;
        }

        // Fill the DP table
        for (int i = 1; i <= N; ++i) {
            for (int s = 0; s <= target; ++s) {
                for (int k = 0; k <= K; ++k) {
                    dp[i][s][k] = dp[i - 1][s][k]; // Not take
                    if (s >= coins[i - 1] && k > 0) {
                        dp[i][s][k] = dp[i][s][k] || dp[i][s - coins[i - 1]][k - 1]; // Take
                    }
                }
            }
        }
        return dp[N][target][K];
    }
};
// class Solution {
//   private:
//     bool solve(int ind, int sum, int k, vector<vector<vector<int>>> &dp, vector<int> &coins){
//         if(!sum && !k) return 1;
//         if(ind<0 || sum<0) return 0;

//         if(dp[ind][sum][k] != -1) return dp[ind][sum][k];

//         int take = solve(ind, sum-coins[ind], k-1, dp, coins);
//         int nTake = solve(ind-1, sum, k, dp, coins);

//         return dp[ind][sum][k] = take || nTake;
//     }
//   public:
//     bool makeChanges(int N, int K, int target, vector<int> &coins) {
//         // code here
//         vector<vector<vector<int>>> dp(N, vector<vector<int>>(target+1, vector<int> (K+1, -1)));
//         return solve(N-1, target, K, dp, coins);
//     }
// };

int main(){
    int N, K, target;   cin>>N>>K>>target;
    vector<int> coins(N, 0);

    for(int i = 0; i<N; i++) cin>>coins[i];
    Solution obj;
    cout<<obj.makeChanges(N, K, target, coins);

    return 0;
}
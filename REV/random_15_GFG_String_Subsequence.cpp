#include<bits/stdc++.h>
using namespace std;

int mod = 1e9+7;
class Solution {
  public:
    int countWays(string s1, string s2) {
        // code here
        int n = s1.length(), m = s2.length();
        vector<int> prev(m+1, 0);
        vector<int> curr(m+1, 0);
        curr[0] = 1;
        prev[0] = 1;

        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=m; j++){
                curr[j] = prev[j]%mod;
                if(s1[i-1] == s2[j-1])
                    curr[j] = (curr[j]+prev[j-1])%mod;
            }
            prev = curr;
        }
        return prev[m];
    }

    /*************************** TABULATION *********************** */
//   public:
//     int countWays(string s1, string s2) {
//         // code here
//         int n = s1.length(), m = s2.length();
//         vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

//         for(int i = 0; i<=n; i++) dp[i][0] = 1;

//         for(int i = 1; i<=n; i++){
//             for(int j = 1; j<=m; j++){
//                 dp[i][j] = dp[i-1][j]%mod;
                
//                 if(s1[i-1] == s2[j-1])
//                     dp[i][j] = (dp[i][j]+dp[i-1][j-1])%mod;
//             }
//         }
//         return dp[n][m];
//     }

    /************************* MEMOIZATION ******************* */
//   private:
//     int solve(int i, int j, string &s1, string &s2,
//     vector<vector<int>> &dp){
//         if(j<0) return 1;
//         if(i<0) return 0;

//         if(dp[i][j] != -1) return dp[i][j];

//         if(s1[i] == s2[j]){
//             int take = solve(i-1, j-1, s1, s2, dp);
//             int nTake = solve(i-1, j, s1, s2, dp);
//             return dp[i][j] = (take+nTake)%mod;
//         }
//         else return dp[i][j] = solve(i-1, j, s1, s2, dp)%mod;
//     }
//   public:
//     int countWays(string s1, string s2) {
//         // code here
//         int n = s1.length(), m = s2.length();
//         vector<vector<int>> dp(n, vector<int>(m, -1));
//         return solve(n-1, m-1, s1, s2, dp)%mod;
//     }
};

int main(){
    string s1, s2;
    cin>>s1>>s2;

    Solution obj;
    cout<<obj.countWays(s1, s2);

    return 0;
}
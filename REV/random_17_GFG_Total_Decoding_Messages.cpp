#include<bits/stdc++.h>
using namespace std;

int mod = 1e9+7;
class Solution {
  public:
    int countWays(string &str) {
        // Code here
        if(str[0] == '0') return 0;
        int n = str.length();
        vector<int> dp(n+1);

        dp[0] = dp[1] = 1;
        for(int i = 2; i<=n; i++){
            if(str[i-1] >= '1') dp[i] = dp[i-1]%mod;
            if(str[i-2] =='1' || str[i-2] == '2' && str[i-1] <='6') dp[i] = (dp[i] + dp[i-2])%mod;
        }
        return dp[n];
    }
//   private:
//     int solve(string &str, int n, vector<int> &dp){
//         if(n == 0 || n == 1) return 1;
//         if(dp[n] != -1) return dp[n];

//         int count = 0;
//         if(str[n-1] >= '1') count = count + solve(str,n-1,dp)%mod;
//         if(str[n-2] =='1' || str[n-2] == '2' && str[n-1] <='6') count = (count + solve(str,n-2,dp)%mod)%mod;

//         return dp[n] = count%mod;
//     }
//   public:
//     int countWays(string &s) {
//         // Code here
//         if(s[0] == '0') return 0;
//         int n = s.length();
//         vector<int> dp(n+1, -1);
//         return solve(s,n , dp)%mod;
//     }
};

int main(){
    string s;
    cin>>s;

    Solution obj;
    cout<<obj.countWays(s);

    return 0;
}
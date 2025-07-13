#include<bits/stdc++.h>
using namespace std;

class Solution{
    private:int mod = 1e9+7;
        int solve(int n, vector<int> &dp){
            if(n == 1) return 1;
            if(n == 2) return 2;
            if(n == 3) return 3;

            if(dp[n] != -1) return dp[n];

            int one = solve(n/2, dp);
            int three = solve(n/3, dp);
            int four = solve(n/4, dp);

            return dp[n] = max(n, (one%mod + three%mod + four%mod)%mod);
        }
    public:
        int maxSum(int n){
            //code here.
            vector<int> dp(n+1, 0);
            dp[1] = 1;
            dp[2] = 2;
            dp[3] = 3;

            for(int i = 4; i<=n; i++)
                dp[i] = max(i, dp[i/2]+dp[i/3]+dp[i/4]);

            return dp[n];
        }

    /************************ MEMOIZATION ****************************** */
    // private:int mod = 1e9+7;
    //     int solve(int n, vector<int> &dp){
    //         if(n == 1) return 1;
    //         if(n == 2) return 2;
    //         if(n == 3) return 3;

    //         if(dp[n] != -1) return dp[n];

    //         int one = solve(n/2, dp);
    //         int three = solve(n/3, dp);
    //         int four = solve(n/4, dp);

    //         return dp[n] = max(n, (one%mod + three%mod + four%mod)%mod);
    //     }
    // public:
    //     int maxSum(int n){
    //         //code here.
    //         vector<int> dp(n+1, -1);
    //         return solve(n, dp);
    //     }
};

int main(){
    int n; cin>>n;
    Solution obj;
    cout<<obj.maxSum(n);

    return 0;
}
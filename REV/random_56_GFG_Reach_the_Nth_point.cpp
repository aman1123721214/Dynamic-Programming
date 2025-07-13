#include<bits/stdc++.h>
using namespace std;

class Solution{
	public:int mod = 1e9+7;
		int nthPoint(int n){
		    // Code here
            int prev2 = 1, prev1 = 1, curr = 0;
            for(int i = 2; i<=n; i++){
                curr = (prev1%mod + prev2%mod)%mod;

                prev2 = prev1;
                prev1 = curr;
            }
            return prev1%mod;
		}

        /*************************** MEMOIZATION ************************** */
    // private:int mod = 1e9+7;
    //     int solve(int steps, vector<int> &dp){
    //         if(steps == 0) return 1;
    //         if(steps < 0) return 0;
    //         if(dp[steps] != -1) return dp[steps];

    //         int one = solve(steps-1, dp)%mod;
    //         int two = solve(steps-2, dp)%mod;

    //         return dp[steps] = (one+two)%mod;
    //     }
	// public:
	// 	int nthPoint(int n){
	// 	    // Code here
    //         vector<int> dp(n+1, -1);
    //         return solve(n, dp);
	// 	}
};

int main(){
    int n; cin>>n;
    Solution obj;
    cout<<obj.nthPoint(n);

    return 0;
}
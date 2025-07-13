#include<bits/stdc++.h>
using namespace std;

class Solution{
  public:int mod = 1e9+7;	
	int distinctSubsequences(string s){
	    // Your code goes here
        int n = s.size();
        vector<long long> dp(n+1, 0);
        unordered_map<char, int> last;
        dp[0] = 1;

        for(int i = 1; i<=n; i++){
            dp[i] = (2*dp[i-1])%mod;

            if(last.find(s[i-1]) != last.end())
                dp[i] = ((dp[i] - dp[last[s[i-1]]]+ mod))%mod;
            last[s[i-1]] = i-1;
        }
        return dp[n]%mod;
        /*
        int n = s.size();
        vector<long long> dp(n+1);
        unordered_map<char, int> last;

        dp[0] = 1;
        for(int i = 1; i<=n; i++){
            dp[i] = 2*dp[i-1];

            if(last.find(s[i-1]) != last.end())
                dp[i] -= dp[last[s[i-1]]];
            last[s[i-1]] = i-1;
        }
        return dp[n]-1;*/
	}
};
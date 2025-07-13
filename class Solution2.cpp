#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
     bool solve(int n , int k , int sum , vector<int> &coins, vector<vector<vector<int>>> &dp){
        if(dp[n][sum][k]!=-1) return dp[n][sum][k];
        if(sum==0 and k==0) return dp[n][sum][k]=true;
        else if(sum==0 || n==0) return dp[n][sum][k]=false; 
       
        dp[n][sum][k]=solve(n-1, k , sum , coins, dp );
        if(dp[n][sum][k]) return dp[n][sum][k];
        if(coins[n-1]<=sum){
            dp[n][sum][k]|=solve(n, k-1 , sum-coins[n-1] , coins ,dp );
        }
        return dp[n][sum][k];
    }
    
    bool makeChanges(int N, int K, int target, vector<int> &coins) {
        // code here
        vector<vector<vector<int>>>dp(N+1, vector<vector<int>>(target+1, vector<int>(K+1,-1)));
        bool flag= false;
        return solve( N ,  K ,  target, coins , dp);
        //return flag;
    }
};
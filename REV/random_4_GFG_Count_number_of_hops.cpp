#include<bits/stdc++.h>
using namespace std;

class Solution {
  private:
    // int solve(int n){
    //     if(n == 3) return 4;
    //     if(n<=2) return n;

    //     return solve(n-1)+solve(n-2)+solve(n-3);
    // }
    int solve(int n,vector<int> &dp){
        if(n == 3) return 4;
        if(n<=2) return n;

        if(dp[n] != -1) return dp[n];

        return dp[n] = solve(n-1, dp)+solve(n-2, dp)+solve(n-3, dp);
    }
  public:
    // Function to count the number of ways in which frog can reach the top.
    int countWays(int n) {
        // your code here
        vector<int> dp(n+1, -1);
        return solve(n, dp);
    }
};

int main(){
    int n; cin>>n;
    Solution obj;
    cout<<obj.countWays(n);
    return 0;
}
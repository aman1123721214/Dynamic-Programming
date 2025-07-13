#include<bits/stdc++.h>
using namespace std;

class Solution {
  private: 
    int solve(int e, int f, vector<vector<int>> &dp){
        if(!e) return 0;
        if(e == 1 || f<=1) return f;

        if(dp[e][f] != -1) return dp[e][f];

        int ans = 1e9;
        for(int i = 1; i<=f; i++)
            ans = min(ans, 1+max(solve(e-1, i-1, dp), solve(e, f-i, dp)));

        return dp[e][f] = ans; 
    }
  public:
    // Function to find minimum number of attempts needed in
    // order to find the critical floor.
    int eggDrop(int n, int k) {
        vector<vector<int>> dp(n+1, vector<int>(k+1, -1));
        return solve(n, k, dp);
    }
};

int main(){
  int n, k; cin>>n>>k;
  Solution obj;
  cout<<obj.eggDrop(n, k);
  return 0;
}
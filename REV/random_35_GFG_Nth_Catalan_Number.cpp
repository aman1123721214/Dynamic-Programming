#include<bits/stdc++.h>
using namespace std;

class Solution {
//   private:
//     int solve(int n){
//         if(n<=1) return 1;

//         int ans = 0;
//         for(int i = 0; i<n; i++)
//             ans+=(solve(i)*solve(n-i-1));
        
//         return ans;
//     }
//   public:
//     // Function to find the nth catalan number.
//     int findCatalan(int n) {
//         // code here
//         return solve(n);
//     }
  private:
    int solve(int n, vector<int> &dp){
        if(n<=1) return 1;
        if(dp[n] != -1) return dp[n];

        int ans = 0;
        for(int i = 0; i<n; i++)
            ans+=(solve(i, dp)*solve(n-i-1, dp));
        
        return dp[n] = ans;
    }
  public:
    // Function to find the nth catalan number.
    int findCatalan(int n) {
        // code here
        vector<int> dp(n+1, -1);
        return solve(n, dp);
    }
};

int main(){
    int n;
    cin>>n;

    Solution obj;
    cout<<obj.findCatalan(n);

    return 0;
}
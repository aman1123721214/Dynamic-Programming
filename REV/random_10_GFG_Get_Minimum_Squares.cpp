#include<bits/stdc++.h>
using namespace std;

class Solution{
//   private:
//     int solve(int n, vector<int> &dp){
//         if(!n) return 0;

//         if(dp[n] != -1) return dp[n];
//         int mini = n;
//         for(int i = 1; i*i<=n; i++){
//             long num = i*i;
//             int rest = n-num;
//             mini = min(mini, 1+solve(rest, dp));
//         }
//         return dp[n] = mini;
//     }
//   public :
//     int MinSquares(int n){
//         vector<int> dp(n+1, -1);
//         return solve(n, dp);
//     }
  public :
    int MinSquares(int n){
        vector<int> dp(n+1, 1e9);
        dp[0]=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j*j<=n;j++) {
                int temp=j*j;
                if(i-temp>=0)
                dp[i]=min(dp[i],1+dp[i-temp]);
            }
        }
        return dp[n];
    }

// public:
//     int MinSquares(int n){
//         if(!n) return 0;
        
//         int mini = 1e9;
//         for(int i = (int)sqrt(n); i>=1; i--){
//             long num = i*i;
//             int rest = n-num;
//             mini = min(mini, 1+MinSquares(rest));
//             return mini;
//         }
//     }
};

int main(){
    int n; cin>>n;
    Solution obj;
    cout<<obj.MinSquares(n);

    return 0;
}
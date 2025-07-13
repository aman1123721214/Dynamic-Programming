#include<bits/stdc++.h>
using namespace std;

class Solution{
  private:int c, d;
    int solve(int a, int b, vector<vector<int>> &dp){
        if((a<=c && b<=d) || (a<=d && b<=c)) return 0;
        if(!a || !b) return 1e9;
        if(dp[a][b] != -1) return dp[a][b];

        int ans = 0;
        // if(a<=c) ans = 1+solve(a, floor(b/2), dp);
        // else if(b<=d) ans = 1+solve(floor(a/2), b, dp);

        ans = min(1+solve(floor(a/2),b, dp), 1+solve(a, floor(b/2), dp));

        return dp[a][b] = ans;
    }
  public:
    int carpetBox(int A, int B, int C, int D){
        //code here
        c = C, d = D;
        vector<vector<int>> dp(A+1, vector<int> (B+1, -1));
        return solve(A, B, dp);
    }
};

int main(){
    int A, B, C, D;
    cin>>A>>B>>C>>D;

    Solution obj;
    cout<<obj.carpetBox(A, B, C, D);

    return 0;
}
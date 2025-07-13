#include<bits/stdc++.h>
using namespace std;

class Solution {
  private: int s, m, l, cs, cm, cl;
    int solve(int x, vector<int> &dp){
        if(x<=0) return 0;
        if(dp[x] != -1) return dp[x];

        int small = cs+solve(x-s, dp);
        int med = cm+solve(x-m, dp);
        int large = cl+solve(x-l, dp);

        return dp[x] = min(small, min(med, large));
    }
  public:
    int getPizza(int X, int S, int M, int L, int CS, int CM, int CL) {
        // code here
        s = S, m = M, l = L, cs = CS, cm = CM, cl = CL;
        vector<int> dp(X+1, -1);
        return solve(X, dp);
    }
};

int main(){
    int X, S, M, L, CS, CM, CL;
    cin>>X>>S>>M>>L>>CS>>CM>>CL;

    Solution obj;
    cout<<obj.getPizza(X, S, M, L, CS, CM, CL);

    return 0;
}
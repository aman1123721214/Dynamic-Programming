#include<bits/stdc++.h>
using namespace std;

class Solution {
  private:vector<vector<double>> dp;
    
    double solve(int k, int r, int c){
        if(r<1 || c<1 || c>r) return 0.0;
        if(r == 1 && c == 1) return k;
        
        if(dp[r][c] != -1.0) return dp[r][c];

        double fromLeftParent = 0.0, fromRightParent = 0.0;
        
        double leftParentWater = solve(k, r-1, c-1);
        if(leftParentWater>1.0)
            fromLeftParent = (leftParentWater-1.0)/2.0;
        
        double rightParentWater = solve(k, r-1, c);
        if(rightParentWater>1.0)
            fromRightParent = (rightParentWater-1.0)/2.0;
        
        return dp[r][c] = fromLeftParent+fromRightParent;
    }
  public:
    double waterOverflow(int K, int R, int C) {
        // code here
        vector<vector<double>> dp(R+1, vector<double> (R+1, 0.0));
        dp[1][1] = K;

        // vector<double> prev(C+1, 0.0), curr(C+1, 0.0);
        // prev[1] = 1.0;

        for(int r = 1; r<=R; r++){
            for(int c = 1; c<=r; c++){
                double overflow = dp[r][c]-1.0;
                dp[r][c] = 1.0;

                dp[r+1][c] += overflow/2.0;
                dp[r+1][c+1] += overflow/2.0;
            }
        }
        return dp[R][C];
    }
};


// class Solution {
//   private:vector<vector<double>> dp;
    
//     double solve(int k, int r, int c){
//         if(r<1 || c<1 || c>r) return 0.0;
//         if(r == 1 && c == 1) return k;
        
//         if(dp[r][c] != -1.0) return dp[r][c];

//         double fromLeftParent = 0.0, fromRightParent = 0.0;
        
//         double leftParentWater = solve(k, r-1, c-1);
//         if(leftParentWater>1.0)
//             fromLeftParent = (leftParentWater-1.0)/2.0;
        
//         double rightParentWater = solve(k, r-1, c);
//         if(rightParentWater>1.0)
//             fromRightParent = (rightParentWater-1.0)/2.0;
        
//         return dp[r][c] = fromLeftParent+fromRightParent;
//     }
//   public:
//     double waterOverflow(int K, int R, int C) {
//         // code here
//         dp.assign(R+1, vector<double> (C+1, -1.0));
//         return solve(K, R, C);
//     }
// };

int main(){
    int K, R, C;
    cin>>K>>R>>C;

    Solution obj;
    cout<<obj.waterOverflow(K, R, C);

    return 0;
}
#include<bits/stdc++.h>
using namespace std;

class Solution {
  private:
  int solve(int n, vector<int> &height, vector<int> &dp){
      if(n <= 1) return height[n];
      if(dp[n] != -1) return dp[n];

      int prev1 = 1e9, prev2 = 1e9;
      if(n-1>=0) prev1 = height[n]+solve(n-1, height, dp);
      if(n-2>=0) prev2 = height[n]+solve(n-2, height, dp);

      return dp[n] = min(prev1, prev2);
  }

  public:
    int minCostClimbingStairs(vector<int>& cost) {
        // Write your code here
        int n = cost.size();
        vector<int> dp(n, -1);
        return min(solve(n-1, cost, dp), solve(n-2, cost, dp));
    }
};

int main(){
    string str;
    getline(cin, str);
    stringstream ss(str);

    int num;
    vector<int> height;
    while(ss>>num) height.push_back(num);

    Solution obj;
    cout<<obj.minCostClimbingStairs(height);

    return 0;
}
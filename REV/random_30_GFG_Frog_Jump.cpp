#include<bits/stdc++.h>
using namespace std;

class Solution {
  private:
    int solve(int n, vector<int> &height, vector<int> &dp){
        if(n == 0) return 0;
        if(dp[n] != -1) return dp[n];

        int prev1 = 1e9, prev2 = 1e9;
        if(n-1>=0) prev1 = abs(height[n]-height[n-1])+solve(n-1, height, dp);
        if(n-2>=0) prev2 = abs(height[n]-height[n-2])+solve(n-2, height, dp);

        return dp[n] = min(prev1, prev2);
    }
  public:
    int minCost(vector<int>& height) {
        // Code here
        int n = height.size();
        vector<int> dp(n, -1);
        return solve(n-1, height, dp);
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
    cout<<obj.minCost(height);

    return 0;
}
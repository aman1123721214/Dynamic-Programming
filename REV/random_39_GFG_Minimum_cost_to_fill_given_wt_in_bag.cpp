#include<bits/stdc++.h>
using namespace std;

class Solution{
  private:
    int solve(int ind, int wt, vector<int> &cost, vector<vector<int>> &dp){
        //base case
        if(!wt) return 0;
        if(ind>wt) return 1e9;
        
        if(dp[ind][wt] != -1) return dp[ind][wt];
        int buy = 1e9, nBuy = 1e9;
        
        if(wt-ind>=0 && cost[ind-1] != -1){ 
            buy = solve(ind, wt-ind, cost, dp);
            if(buy != 1e9) buy+=cost[ind-1];
        }

        nBuy = solve(ind+1, wt, cost, dp);

        return dp[ind][wt] = min(buy, nBuy);
    }
  public:
    int minimumCost(int n, int wt, vector<int> &cost){
        //Code Here
        vector<vector<int>> dp(n+1, vector<int>(wt+1, -1));
        return solve(1, wt, cost, dp);
    }
//   private:
//     int solve(int ind, int wt, vector<int> &cost, vector<vector<int>> &dp){
//         //base case
//         if(ind == wt) return cost[ind-1];
//         if(ind>wt) return 1e9;
        
//         if(dp[ind][wt] != -1) return dp[ind][wt];

//         int buy = 1e9, nBuy = 1e9;
//         if(wt-ind>=0 && cost[ind-1] != -1) 
//             buy = cost[ind-1]+solve(ind, wt-ind, cost, dp);
//         if(ind+1<=wt)
//             nBuy = solve(ind+1, wt, cost, dp);

//         return dp[ind][wt] =  min(buy, nBuy);
//     }
//   public:
//     int minimumCost(int n, int wt, vector<int> &cost){
//         //Code Here
//         vector<vector<int>> dp(n, vector<int> (wt, -1));
//         return solve(1, wt, cost, dp);
//     }
};

int main(){
    int n, wt;
    cin>>n>>wt;
    vector<int> arr(n);

    for(int i = 0; i<n; i++) cin>>arr[i];

    Solution obj;
    cout<<obj.minimumCost(n, wt, arr);

    return 0;
}
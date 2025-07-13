#include<bits/stdc++.h>
using namespace std;


class Solution {
  private:
    int solve(int ind, int sum, int *arr, vector<vector<int>> &dp){
        if(sum && (sum==2024 || !(sum%20) || !(sum%24)))return 1;
        if(ind<0 || sum>2024) return 0;

        if(dp[ind][sum] != -1) return dp[ind][sum];

        int take = solve(ind-1, sum+arr[ind], arr, dp);
        int nTake = solve(ind-1, sum, arr, dp);

        return dp[ind][sum] = take || nTake;
    }    
  public:
    int isPossible(int N , int coins[]) {
        //Code here
        vector<vector<int>> dp(N, vector<int>(2024, -1));
        return solve(N-1, 0, coins, dp);
    }
};

int main(){
    int N;  cin>>N;
    int *coins = new int[N];
    for(int i = 0; i<N; i++) cin>>coins[i];

    Solution obj;
    cout<<obj.isPossible(N, coins);

    return 0;
}
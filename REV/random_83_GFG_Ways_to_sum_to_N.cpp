#include<bits/stdc++.h>
using namespace std;

class Solution {
  private: const int mod = 1e9+7;
    long long solve(int sum, int *arr, int m, vector<long long> &dp){
        if(sum<0) return 0;
        if(!sum) return 1;

        if(dp[sum] != -1) return dp[sum];

        long long ways = 0;
        for(int i = 0; i<m; i++){
            ways = (ways+solve(sum-arr[i], arr, m, dp))%mod;
        }
        return dp[sum] = ways;
    }
  public:
    // function to count the total  
    // number of ways to sum up to 'N' 
    int countWays(int arr[], int m, int N) { 
        //code here
        vector<long long> dp(N+1, -1);
        return solve(N, arr, m, dp);
    } 
};

int main(){
    int m, N;   cin>>m>>N;

    int *arr = new int[m];
    for(int i = 0; i<m; i++) cin>>arr[i];

    Solution obj;
    cout<<obj.countWays(arr, m, N);

    return 0;
}
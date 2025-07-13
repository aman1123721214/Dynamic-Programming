#include<bits/stdc++.h>
using namespace std;

class Solution{
    private:
    bool solve(int ind, int k, vector<int> &arr, vector<vector<int>> &dp){
        if(k == 0) return 1;
        if(ind<0 || k<0) return k==0?1:0;

        if(dp[ind][k] != -1) return dp[ind][k];
        
        bool take = solve(ind-1, k-arr[ind], arr, dp);
        bool nTake = solve(ind-1, k, arr, dp);

        return dp[ind][k] = take || nTake;
    }
    public:
    bool checkSubsequenceSum(int n, vector<int>& arr, int k) {
        // Code here
        vector<vector<int>> dp(n, vector<int> (k+1, -1));
        return solve(n-1, k, arr, dp);
    }
};

int main(){
    int n, k; cin>>n>>k;
    vector<int> arr(n);
    for(int i = 0; i<n; i++) cin>>arr[i];

    Solution obj;
    cout<<obj.checkSubsequenceSum(n, arr, k);

    return 0;
}
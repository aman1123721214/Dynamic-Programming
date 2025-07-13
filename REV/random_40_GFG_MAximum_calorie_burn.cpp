#include<bits/stdc++.h>
using namespace std;

class Solution{
  private:
    int solve(int ind, bool flag, int n, int *arr, vector<vector<int>> dp){
        if(ind == n-1) return arr[ind];
        if(ind == n) return 0;

        if(dp[ind][flag] != -1) return dp[ind][flag];
        int take = 0, nTake = 0;
        
        if(flag) take = arr[ind]+solve(ind+2, 0, n, arr, dp);
        else take = arr[ind]+solve(ind+1, 1, n, arr, dp);

        nTake = solve(ind+1, 0, n, arr, dp);
        return dp[ind][flag] = max(take, nTake);
    }
  public:
    int maxCalorie(int arr[], int n){
        //Code Here
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return solve(0, 0, n, arr, dp);
    }
};

int main(){
    int n; cin>>n;
    int arr[n];
    for(int i = 0; i<n; i++) cin>>arr[i];

    Solution obj;
    cout<<obj.maxCalorie(arr, n);
    
    return 0;
}
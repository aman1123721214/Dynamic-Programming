#include<bits/stdc++.h>
using namespace std;

class Solution {
  private:
    int solve(int i, int j, vector<int> &arr,
         vector<vector<int>> &dp){
        if(i>j) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        int maxi = -1e9;
        for(int ind = i; ind<=j; ind++){
            int cost = arr[i-1]*arr[ind]*arr[j+1]+
            solve(i, ind-1, arr, dp)+solve(ind+1, j, arr, dp);

            maxi = max(maxi, cost);
        }
        return dp[i][j] = maxi;
    }
  public:
    int maxCoins(vector<int> &arr) {
        // code here
        int n = arr.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));

        arr.insert(arr.begin(), 1);
        arr.push_back(1);

        return solve(1, n, arr, dp);
    }
};

int main(){
    string str;
    getline(cin, str);
    stringstream ss(str);

    int num;
    vector<int> arr;
    while(ss>>num)
        arr.push_back(num);
    
    Solution obj;
    cout<<obj.maxCoins(arr);

    return 0;
}
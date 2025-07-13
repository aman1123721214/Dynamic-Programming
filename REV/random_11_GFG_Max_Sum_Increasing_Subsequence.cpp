#include<bits/stdc++.h>
using namespace std;

class Solution {
  private:
    int solve(int curr, int prev, vector<int> &arr,
    vector<vector<int>> &dp){
        if(curr == arr.size()) return 0;

        if(prev != -1 && dp[curr][prev] != -1) return dp[curr][prev];

        int take = 0, nTake = 0;
        if(prev != -1 && arr[prev]<arr[curr])
            take = arr[curr]+solve(curr+1, curr, arr, dp);
        nTake = solve(curr+1, prev, arr, dp);

        return dp[curr][prev] = max(take, nTake);
    }

  public:
    int maxSumIS(vector<int>& arr) {
        // Your code goes here
        int n = arr.size();
        int ans = 0;

        vector<int> dp(n,-1);

        for(int i = n-1; i>=0; i--){
            int currSum = 0;
            for(int j = i; j<n; j++){
                if(arr[j]>arr[i]){
                    currSum = max(dp[j], currSum);
                }
            }
            dp[i] = currSum+ arr[i];
            ans = max(ans, dp[i]);
        }
        return ans;
    }
//   private:
//     int solve(int curr, int prev, vector<int> &arr,
//     vector<vector<int>> &dp){
//         if(curr == arr.size()) return 0;

//         if(prev != -1 && dp[curr][prev] != -1) return dp[curr][prev];

//         int take = 0, nTake = 0;
//         if(prev == -1 || arr[prev]<arr[curr])
//             take = arr[curr]+solve(curr+1, curr, arr, dp);
//         nTake = solve(curr+1, prev, arr, dp);

//         return dp[curr][prev] = max(take, nTake);
//     }

//   public:
//     int maxSumIS(vector<int>& arr) {
//         // Your code goes here
//         int n = arr.size();
//         vector<vector<int>> dp(n, vector<int>(n, -1));
//         return solve(0, -1, arr, dp);
//     }
};

int main(){
    string str;
    getline(cin, str);
    stringstream ss(str);
    int num;
    vector<int> arr;
    
    while(ss>>num) arr.push_back(num);

    Solution obj;
    cout<<obj.maxSumIS(arr);

    return 0;
}
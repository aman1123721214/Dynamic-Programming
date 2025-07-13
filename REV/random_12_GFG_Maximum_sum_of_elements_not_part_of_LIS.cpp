#include<bits/stdc++.h>
using namespace std;

class Solution {
  private:
    int solve(int curr, int prev, int *arr, int n,
    vector<vector<int>> &dp){
        
    }

  public:
    int maxSumLis(int arr[], int n) {
        // code here
        int sum = arr[0];
        vector<int> temp;
        temp.push_back(arr[0]);

        for(int i = 1; i<n; i++){
            sum+=arr[i];
            if(arr[i]>temp.back()) temp.push_back(arr[i]);
            else{
                int lb = lower_bound(temp.begin(), temp.end(), arr[i])-temp.begin();
                temp[lb] = arr[i];
            }
        }

        int tempSum = 0;
        for(int it: temp) tempSum+=it;
        return sum-tempSum;
    }
/*
9
15 6 11 8 2 2 10 15 5 = 35
*/

//   private:
//     int solve(int curr, int prev, int *arr, int n,
//     vector<vector<int>> &dp){
//         if(curr == n) return 0;

//         if(prev != -1 && dp[curr][prev] != -1) return dp[curr][prev];

//         int take = 0, nTake = 0;
//         if(prev == -1 || arr[prev]<arr[curr])
//             take = arr[curr]+solve(curr+1, curr, arr, n, dp);
//         nTake = solve(curr+1, prev, arr, n, dp);

//         return dp[curr][prev] = max(take, nTake);
//     }

//   public:
//     int maxSumLis(int arr[], int n) {
//         // code here
//         //return solve(0, -1, Arr, n);
//         int sum = 0;
//         for(int i = 0; i<n; i++) sum+=arr[i];

//         vector<vector<int>> dp(n, vector<int>(n, -1));
//         return sum-solve(0, -1, arr, n, dp);
//     }
};

int main(){
    int n; cin>>n;
    int *arr = new int[n];
    for(int i = 0; i<n; i++) cin>>arr[i];
    
    Solution obj;
    cout<<obj.maxSumLis(arr, n);

    return 0;
}
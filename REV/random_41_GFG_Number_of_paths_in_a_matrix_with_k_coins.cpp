#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int solve(int row, int col, int k, vector<vector<int>> &arr,
    vector<vector<vector<long long>>> &dp){
        if(row == 0 && col == 0 && k == arr[0][0]) return 1;
        if(row<0 || col<0 || k<0) return 0;

        if(dp[row][col][k] != -1) return dp[row][col][k];

        long long up = solve(row-1, col, k-arr[row][col], arr, dp);
        long long left = solve(row, col-1, k-arr[row][col], arr, dp);

        return dp[row][col][k] = up+left;
    }
public:
    long long numberOfPath(int n, int k, vector<vector<int>> &arr){
        // Code Here
        vector<vector<vector<long long>>> dp(n,
        vector<vector<long long>> (n, 
        vector<long long> (k+1, -1)));

        return solve(n-1, n-1, k, arr, dp);
    }
};

int main(){
    int n, k;
    cin>>n>>k;

    vector<vector<int>> arr(n, vector<int> (n));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++)
            cin>>arr[i][j];
    }

    Solution obj;
    cout<<obj.numberOfPath(n, k, arr);

    return 0;
}
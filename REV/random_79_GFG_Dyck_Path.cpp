#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long dyckPaths(int N) {
        // Compute Catalan number C_N using binomial coefficient
        long long catalan = 1;
        for (int i = 0; i < N; ++i) {
            catalan = catalan * (2 * N - i) / (i + 1);
        }
        return catalan / (N + 1);
    }
};
// class Solution {
//   private:int n;
//     long long solve(int row, int col, vector<vector<long long>> &dp){
//         if(!row && col == n-1) return 1;
//         if(row<0 || col>=n || row+col>=n) return 0;

//         if(dp[row][col] != -1) return dp[row][col];
//         long long count = 0;
//         count =  solve(row-1, col, dp)+solve(row, col+1, dp);
//         return dp[row][col] = count;
//     }
//   public:
//     long long dyckPaths(int N) {
//         // code here
//         n = N;
//         vector<vector<long long>> dp(N, vector<long long>(N, -1));
//         return solve(N-1, 0, dp);
//     }
// };

int main(){
    int N;  cin>>N;
    Solution obj;
    cout<<obj.dyckPaths(N);

    return 0;
}
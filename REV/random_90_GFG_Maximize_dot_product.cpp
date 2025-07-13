#include<bits/stdc++.h>
using namespace std;

// class Solution {
//     public:
//         long long maxDotProduct(int n, int m, int a[], int b[]) {
//             // Create a DP table of size (n+1) x (m+1)
//             vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, 0));
    
//             // Fill the DP table iteratively
//             for (int i = 1; i <= n; i++) {
//                 for (int j = 1; j <= m; j++) {
//                     // Option 1: Take the current pair (a[i-1], b[j-1])
//                     long long take = a[i-1] * static_cast<long long>(b[j-1]) + dp[i-1][j-1];
    
//                     // Option 2: Skip the current b[j-1]
//                     long long skip = max(dp[i][j-1], dp[i-1][j]);
    
//                     // Store the maximum of the two options in dp[i][j]
//                     dp[i][j] = max(take, skip);
//                 }
//             }
    
//             // The final answer is in dp[n][m]
//             return dp[n][m];
//         }
//     };


// class Solution{
//   public:
// 	int maxDotProduct(int n, int m, int a[], int b[]) { 
// 		// Your code goes here
//         vector<long long> curr(n+1, 0), prev(n+1, 0);

//         for(int i = 1; i<=n; i++){
//             for(int j = 1; j<=m; j++){

//                 long long take = a[i-1]*b[j-1] +prev[j-1];
//                 long long nTake = max(curr[j-1], prev[j]);

//                 curr[j] = max(take, nTake);
//             }
//             prev = curr;
//         }
//         return prev[m];
// 	} 
// };


// class Solution {
//     private:
//         long long solve(int i, int j, int *a, int *b, vector<vector<long long>> &dp) {
//             if (i < 0 || j < 0) return 0; 
    
//             if (dp[i][j] != -1) return dp[i][j];
    
//             long long take = a[i] * b[j] + solve(i - 1, j - 1, a, b, dp);
//             long long nTake = solve(i, j - 1, a, b, dp);
    
//             return dp[i][j] = max(take, nTake);
//         }
    
//     public:
//         int maxDotProduct(int n, int m, int a[], int b[]) {
//             vector<vector<long long>> dp(n, vector<long long>(m, -1));
//             return solve(n - 1, m - 1, a, b, dp);
//         }
//     };

// class Solution {
//     private:
//         long long solve(int i, int j, int *a, int *b, vector<vector<long long>> &dp) {
//             if (j < 0) return 0; // All elements in b have been placed
//             if (i < 0) return -1e9; // Not enough elements in a to place remaining b elements (invalid case)
            
//             if (dp[i][j] != -1) return dp[i][j];
            
//             long long take = a[i] * b[j] + solve(i - 1, j - 1, a, b, dp);
//             long long nTake = solve(i - 1, j, a, b, dp);
            
//             return dp[i][j] = max(take, nTake);
//         }
    
//     public:
//         int maxDotProduct(int n, int m, int a[], int b[]) {
//             vector<vector<long long>> dp(n, vector<long long>(m, -1));
//             return solve(n - 1, m - 1, a, b, dp);
//         }
//     };
class Solution {
    public:
        int maxDotProduct(int n, int m, int a[], int b[]) {
            vector<vector<long long>> dp(n+1, vector<long long>(m+1, 0));
            for(int j = 1; j<=m; j++) dp[0][j] = -1e9;
            
            for(int i = 1; i<=n; i++){
                for(int j = 1; j<=m; j++){
                    long long take = a[i-1]*b[j-1] +dp[i-1][j-1];
                    long long nTake = dp[i-1][j];

                    dp[i][j] = max(take, nTake);
                }
            }
            return dp[n][m];
        }
    };

int main(){
    int n, m;   cin>>n>>m;

    int *a = new int[n];
    int *b = new int[m];

    for(int i = 0; i<n; i++) cin>>a[i]; 
    for(int i = 0; i<m; i++) cin>>b[i];
    
    Solution obj;
    cout<<obj.maxDotProduct(n, m, a, b);

    return 0;
}
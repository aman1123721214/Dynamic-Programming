// #include <bits/stdc++.h>
// using namespace std;
// int mod = 1000000007;

/******************************************** MEMOIZATION ************************************************ */
// int solve(int row, int col, vector<vector<int>> &mat, int n, vector<vector<int>> &dp){
//     if(row == 0 && col == 0) return mat[0][0];
//     if(row<0 || col<0 || row>=n || col>=n) return 0;
//     if(dp[row][col] != -1) return dp[row][col];

//     int up = mat[row][col]+solve(row-1, col, mat, n, dp);
//     int ldg = mat[row][col]+solve(row-1, col-1, mat, n, dp);
//     int rdg = mat[row][col]+solve(row-1, col+1, mat, n, dp);

//     return dp[row][col] = max(up, max(ldg, rdg));
// }
// int maximumPath(int n, vector<vector<int>> mat){
//     // code here
//     int maxi = -1e9;
//     for(int i = 0; i<n; i++){
//         vector<vector<int>> dp(n, vector<int> (n, -1));
//         int ans = solve(n-1, i, mat, n, dp);
//         maxi = max(ans, maxi);
//     }return maxi;
// }

/********************************************* TABULATION ************************************************ */
// int maximumPath(int n, vector<vector<int>> mat){
//     // code here
//       vector<vector<int>> dp(n, vector<int> (n, 0));
//       dp[n-1] = mat[n-1];
      
//       for(int row = n-2; row>=0; row--){
//           for(int col = 0; col<n; col++){
//               int up = mat[row][col]+dp[row+1][col];
//               int ldg = -1e9;
//               if(col-1>=0) ldg = mat[row][col]+dp[row+1][col-1];
//               int rdg = -1e9;
//               if(col+1<n) rdg = mat[row][col] + dp[row+1][col+1];
              
//               dp[row][col] = max({up, ldg, rdg});
//           }
//       }
//       int maxi = -1e9;
//       for(int col = 0; col<n; col++){
//           maxi = max(maxi, dp[0][col]);
//       }return maxi;
//     }

/**************************************** MAX SPACE OPT ************************************************** */
// int maximumPath(int n, vector<vector<int>> mat){
//     // code here
//     vector<int> prev(n, 0), curr(n, 0);
//     for(int i = 0; i<n; i++) prev[i] = mat[n-1][i];

//     for(int row = n-2; row>=0; row--){
//         for(int col = 0; col<n; col++){
//             int up = mat[row][col]+prev[col];
//             int ldg = -1e9;
//             if(col-1>=0) ldg = mat[row][col]+prev[col-1];
//             int rdg = -1e9;
//             if(col+1<n) rdg = mat[row][col]+prev[col+1];

//             curr[col] = max({up, ldg, rdg});
//         }prev = curr;
//     }

//     int maxi = -1e9;
//     for(int i = 0; i<n; i++) maxi = max(maxi, prev[i]);
//     return maxi;
// }

/********************************************** MAIN ***************************************************** */
// int main(){
//     int n;
//     cin>>n;
//     vector<vector<int>> mat(n, vector<int> (n, 0));
//     for(int i = 0; i<n; i++)
//         for(int j = 0; j<n; j++)
//             cin>>mat[i][j];
    
//     cout<<maximumPath(n, mat);
// }
// #include<iostream>
// #include<bits/stdc++.h>
// using namespace std;

/****************************************** MEMOIZATION ******************************************************* */
// int findMinimumCost(int i, int j, vector<int> &cuts, vector<vector<int>> &dp) {
//     // Base case: If i is greater than j, there are no cuts to consider.
//     if (i > j) return 0;
//     if(dp[i][j] != -1) return dp[i][j];

//     int mini = INT_MAX;
//     for (int ind = i; ind <= j; ind++) {
//         int ans = cuts[j + 1] - cuts[i - 1] +
//                   findMinimumCost(i, ind - 1, cuts, dp) +
//                   findMinimumCost(ind + 1, j, cuts, dp);
//         mini = min(mini, ans);
//     }
//     return dp[i][j] = mini;
// }
// int cost(int n, int c, vector<int> &cuts){
//     // Write your code here.
//     cuts.push_back(n);
//     cuts.insert(cuts.begin(), 0);
//     vector<vector<int>> dp(c+1, vector<int> (c+1, -1));
//     sort(cuts.begin(), cuts.end());
//     return findMinimumCost(1, c, cuts, dp);
// }

/******************************************* TABULATION ********************************************************* */
// int cost(int n, int c, vector<int> &cuts){
//     // Write your code here.
//     cuts.push_back(n);
//     cuts.insert(cuts.begin(), 0);
//     sort(cuts.begin(), cuts.end());
//     vector<vector<int>> dp(c+2, vector<int> (c+2, 0));
    
//     for(int i = c; i>=1; i--){
//         for(int j = 1; j<=c; j++){
//             if(i>j) continue;
//             int mini = INT_MAX;
//             for (int ind = i; ind <= j; ind++) {
//                 int ans = cuts[j + 1] - cuts[i - 1] + dp[i][ind - 1]+dp[ind + 1][j];
//                 mini = min(mini, ans);
//             }
//             dp[i][j] = mini;
//         }
//     }
//     return dp[1][c];
// }

/******************************************* MAIN *************************************************************** */
// int main(){
//     int n, c;
//     cin>>n>>c;
//     vector<int> arr(n, 0);
//     for(int i = 0; i<n; i++) cin>>arr[i];
//     cout<<cost(n, c, arr);
//     return 0;
// }
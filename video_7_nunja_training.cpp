// #include<iostream>
// #include<bits/stdc++.h>
// using namespace std;

// int solve(int days, int last, vector<vector<int>> &points, vector<vector<int>> &dp){
//     if(days == 0){
//         int maxi = 0;
//             for(int task = 0; task<3; task++){
//                 if(task != last)
//                     maxi = max(maxi, points[0][task]);
//             }
//         return maxi;
//     }

//     if(dp[days][last] != -1) return dp[days][last];
//     int maxi = 0;

//     for(int task = 0; task<3; task++){
//         if(task != last){
//             int point = points[days][task]+
//             solve(days-1, task, points, dp);
//             maxi = max(maxi, point);
//         }
//     }
//     return dp[days][last] = maxi;
// }

// int ninjaTraining(int n, vector<vector<int>> &points){
//     // Write your code here.
//     vector<vector<int>> dp(n, vector<int> (4, -1));
//     return solve(n-1, 3, points, dp);
// }
// #include<iostream> 
// #include<bits/stdc++.h>
// using namespace std;

/* ALL STOCKS RELATED PROBLEMS REQUIRES HANDELLING OF SPACE COMPLEXITY */

// int maximumProfit(vector<int> &prices){
//     // Write your code here.
//     int mini = prices[0], profit = 0, n = prices.size();
//     for(int i = 1; i<n; i++){
//         int cost = prices[i]-mini;
//         profit = max(cost, profit);
//         mini = min(prices[i], mini);
//     }
//     return profit;
// }

// int main(){
//     int n;
//     cin>>n;
//     vector<int> prices(n, 0);
//     for(int i = 0; i<n; i++) cin>>prices[i];
//     cout<<maximumProfit(prices);
//     return 0;
// }


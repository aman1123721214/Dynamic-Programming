#include<bits/stdc++.h>
using namespace std;

//NORMAL
// int fibb(int n, vector<int> &dp ){

//     if(n<=1) return n;

//     if(dp[n] != -1) return dp[n];
//     return dp[n] = fibb(n-1, dp)+ fibb(n-2, dp);
// }
// int main(){
//     int num;
//     cout<<"enter the number: ";
//     cin>>num;
//     vector<int> dp(num+1, -1);

//     cout<<fibb(num, dp);
//     return 0;
// }

//TABULATION
// int fibb(int num, vector<int> &dp){
//     for(int i = 2; i<=num; i++){
//         dp[i] = dp[i-1]+dp[i-2];
//     }
// }
// int main(){
//     int num;
//     cout<<"enter the number: ";
//     cin>>num;
//     vector<int> dp(num+1);
//     dp[0] = 0, dp[1] = 1;

//     fibb(num, dp);

//     for(auto it: dp){
//         cout<<it<<" ";
//     }
// }


// int main(){
//     int prev2 = 0, prev1 = 1, num;
//     int curr;

//     cout<<"enter the number: ";
//     cin>>num;

//     for(int i = 2; i<=num; i++){
//         curr = prev1+prev2;
//         cout<<curr<<" ";
//         prev2 = prev1;
//         prev1 = curr;
//     }
//     return 0;
// }
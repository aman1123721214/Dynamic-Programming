#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    long long int distinctColoring(int N, int r[], int g[], int b[]){
        // code here 
        vector<vector<long long int>> dp(N,vector<long long int>(3,0));
        dp[0][0]=r[0];
        dp[0][1]=g[0];
        dp[0][2]=b[0];
        
        for(int i=1;i<N;i++){
            dp[i][0] = min(dp[i-1][1],dp[i-1][2]) + r[i];
            dp[i][1] = min(dp[i-1][0],dp[i-1][2]) + g[i];
            dp[i][2] = min(dp[i-1][0],dp[i-1][1]) + b[i];
        }
        
        return min(dp[N-1][0],min(dp[N-1][1],dp[N-1][2]));
    }
// private:
// long long ans = 0;
//     long long solve(int ind, int prev, int N, int r[], int g[], int b[],
//     vector<vector<long long>> &dp){
//         //base case
//         if(ind == 0){
//             long long mini = 1e11;
//             for(int color = 0; color<3; color++){
//                 if(color!=prev){
//                     if(color == 0) mini = min(mini, (long long)r[ind]);
//                     if(color == 1) mini = min(mini, (long long)g[ind]);
//                     if(color == 2) mini = min(mini, (long long)b[ind]);
//                 }
//             }
//             return dp[ind][prev] = mini;
//         }

//         if(dp[ind][prev] != -1) return dp[ind][prev];

//         long long mini = 1e11;
//         for(int color = 0; color<3; color++){
//             if(color != prev){
//                 if(color == 0) mini = min(mini, r[ind]+solve(ind-1, 1, N, r, g, b, dp));
//                 if(color == 1) mini = min(mini, g[ind]+solve(ind-1, 2, N, r, g, b, dp));
//                 if(color == 2) mini = min(mini, b[ind]+solve(ind-1, 3, N, r, g, b, dp));
//             }
//         }
//         return dp[ind][prev] = mini;
//     }
// public:
//     long long int distinctColoring(int N, int r[], int g[], int b[]){
//         // code here 
//         vector<vector<long long>> dp(N, vector<long long> (4, -1));
//         return solve(N-1, 3, N, r, g, b, dp);
//     }
};

int main(){
    int n; cin>>n;
    int *r = new int[n];
    int *g = new int[n];
    int *b = new int[n];

    
    for(int i = 0; i<n; i++) cin>>r[i];
    for(int i = 0; i<n; i++) cin>>g[i];
    for(int i = 0; i<n; i++) cin>>b[i];
    cout<<endl;

    cout<<"ans = ";
    Solution obj;
    cout<<obj.distinctColoring(n, r, g, b);
}   
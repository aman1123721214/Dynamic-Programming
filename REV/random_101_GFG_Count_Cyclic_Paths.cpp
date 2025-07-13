#include<bits/stdc++.h>
using namespace std;

// class Solution{   
// private:int mod = 1e9+7;
// vector<vector<int>> dp;
   
//     int solve(int node, int pathLen, vector<int> adj[]){
//         //Code here
//         if(node == 0 && pathLen == 0) return 1;
//         if(pathLen<0) return 0;

//         if(dp[node][pathLen] != -1) return dp[node][pathLen];

//         int paths = 0;
//         for(int it:adj[node])
//             paths = (paths+solve(it, pathLen-1, adj))%mod;
        
//         return dp[node][pathLen] = paths;
//     }
// public:
//     int countPaths(int N){
//         // code here 
//         dp.assign(4, vector<int> (N+1, 0));

//         vector<int> adj[4];
//         adj[0] = {1, 2, 3};
//         adj[1] = {0, 2, 3};
//         adj[2] = {1, 0, 3};
//         adj[3] = {1, 2, 0};

//        // return solve(0, N, adj);

//         dp[0][0] = 1;

//         for(int pathLen = 1; pathLen <=N; pathLen++) {
//             for(int node = 0; node<4; node++) {
//                 dp[node][pathLen] = 0;
//                 for(int neighbour : adj[node]){
//                     dp[node][pathLen] = (dp[node][pathLen] + dp[neighbour][pathLen-1]) %mod;
//                 }
//             }
//         }
//         return dp[0][N];

//     }
// };
class Solution{   
private:int mod = 1e9+7;
vector<vector<int>> dp;
   
    int solve(int node, int pathLen, vector<int> adj[]){
        //Code here
        if(node == 0 && pathLen == 0) return 1;
        if(pathLen<0) return 0;

        if(dp[node][pathLen] != -1) return dp[node][pathLen];

        int paths = 0;
        for(int it:adj[node])
            paths = (paths+solve(it, pathLen-1, adj))%mod;
        
        return dp[node][pathLen] = paths;
    }
public:
    int countPaths(int N){
        // code here 
        if(N==1) return 0;
        dp.assign(4, vector<int> (N+1, -1));

        vector<int> adj[4];
        adj[0] = {1, 2, 3};
        adj[1] = {0, 2, 3};
        adj[2] = {1, 0, 3};
        adj[3] = {1, 2, 0};

        return solve(0, N, adj);
    }
};

int main(){
    int n;  cin>>n;
    Solution obj;
    cout<<obj.countPaths(n);

    return 0;
}
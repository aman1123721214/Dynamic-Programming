#include<bits/stdc++.h>
using namespace std;

int solve(int i, int j, string &s1, string &s2, 
    vector<vector<int>> &dp){
        if(i<0 || j<0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        
        int match = 0, not_match = 0;
        if(s1[i] == s2[j])
            match = 1+solve(i-1, j-1, s1, s2, dp);
        not_match = solve(i-1, j, s1, s2, dp);

        return dp[i][j] = max(match, not_match);
    }
int maxSubsequenceSubstring(string X, string Y, int N, int M){
    //code
    int maxi = 0;
    vector<vector<int>> dp(N+1, vector<int>(M+1, -1));
    for(int i = M-1; i>=0; i--)
        maxi = max(maxi, solve(N-1, i, X, Y, dp));

    return maxi;
}

int main(){
    string X, Y;
    cin>>X>>Y;

    int N, M;
    cin>>N>>M;

    cout<<maxSubsequenceSubstring(X, Y, N, M);

    return 0;
}
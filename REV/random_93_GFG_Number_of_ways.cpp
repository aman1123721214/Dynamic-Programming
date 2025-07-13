#include<bits/stdc++.h>
using namespace std;

class Solution{
private:
    long long solve(int n, vector<long long> &dp){
        //10if(!n) return 1;
        if(n<4) return 1;
        
        if(dp[n] != -1) return dp[n];

        long long horizStck = solve(n-1, dp);
        long long vertStck = solve(n-4, dp);

        return dp[n] = horizStck+vertStck;
    }
public:
    long long int arrangeTiles(int N){
        // code here
        vector<long long> dp(N+1, -1);
        return solve(N, dp);
    }
};

int main(){
    int N;  cin>>N;
    Solution obj;
    cout<<obj.arrangeTiles(N);

    return 0;
}
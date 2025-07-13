#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    int findWinner(int n, int x, int y) {
        vector<bool>dp(n+1,false); 
        dp[0]=false;
        
        for(int i=1;i<=n;i++){
            if(i>=1 && !dp[i-1]) dp[i]=true;
            if(i>=x && !dp[i-x]) dp[i]=true;
            if(i>=y && !dp[i-y]) dp[i]=true;
        }
        return dp[n] ? 1 : 0;
    }
};

int main(){
    int n, x, y;
    cin>>n>>x>>y;

    Solution obj;
    cout<<obj.findWinner(n, x, y);

    return 0;
}
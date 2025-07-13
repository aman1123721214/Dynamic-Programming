#include<bits/stdc++.h>
using namespace std;

class Solution{
  private:
    int solve(int n, vector<int> &dp){
        if(n == 1) return 0;
        if(n == 2 || n == 3) return 1;
        if(dp[n] != -1) return dp[n];

        int two = 1e9, three = 1e9, other = 1e9;

        if(!(n%2)) two = solve(n/2, dp);
        if(!(n%3)) three = solve(n/3, dp);
        else other = solve(n-1, dp);

        return dp[n] = 1+min(two, min(three, other));
    } 
  public:
	int minSteps(int N) { 
	    // Your code goes here
        vector<int> dp(N+1, -1);
        return solve(N, dp);
	} 
};

int main(){
    int n; cin>>n;
    Solution obj;
    cout<<obj.minSteps(n);

    return 0;
}
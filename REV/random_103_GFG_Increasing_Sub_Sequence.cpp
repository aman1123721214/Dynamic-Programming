#include<bits/stdc++.h>
using namespace std;

class Solution {
  private:vector<vector<int>> dp;
    int solve(int curr, int prev, vector<int> &arr){
        if(curr == arr.size()) return 0;
        if(dp[curr][prev+1] != -1) return dp[curr][prev+1];

        int take = 0, nTake = 0;
        if(prev == -1 || arr[curr]>arr[prev])
            take = 1+solve(curr+1, curr, arr);
        nTake = solve(curr+1, curr, arr);

        return dp[curr][prev+1] = max(take, nTake);
    }
  public:
    int maxLength(string& s) {
        // code here
        int n = s.length();
        vector<int> arr(n);
        dp.assign(n+1, vector<int>(n+2, -1));

        for(int i = 0; i<n; i++)
            arr[i] = (s[i]-'a');

        return solve(0, -1, arr);
    }
};

int main(){
    string str;
    cin>>str;

    Solution obj;
    cout<<obj.maxLength(str);

    return 0;
}
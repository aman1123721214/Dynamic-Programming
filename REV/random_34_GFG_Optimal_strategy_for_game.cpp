#include<bits/stdc++.h>
using namespace std;

class Solution{
  private:
    int solve(int st, int end, vector<int> &arr, vector<vector<int>> &dp){
        if(st>end) return 0;
        if(st == end) return arr[st];

        if(dp[st][end] != -1) return dp[st][end];

        int first = arr[st]+ min(solve(st+2, end, arr, dp), solve(st+1, end-1, arr, dp));
        int last = arr[last]+ min(solve(st, last-2, arr, dp), solve(st+1, end-1, arr, dp));

        return dp[st][end] = max(first, last);
    }
  public:
    int maximumAmount(vector<int> arr){
        //Code Here
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(0, n-1, arr, dp);
    }
};

int main(){
    string str;
    getline(cin, str);
    stringstream ss(str);

    int num;
    vector<int> arr;
    while(ss>>num) arr.push_back(num);
    
    Solution obj;
    cout<<obj.maximumAmount(arr);

    return 0;
}
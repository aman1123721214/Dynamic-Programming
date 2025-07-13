#include<bits/stdc++.h>
using namespace std;

class Solution {
  private: 
    int solve(int ind, vector<int> &arr, vector<int> &dp){
        int n = arr.size();
        if(ind == n) return 0;

        if(dp[ind] != -1) return dp[ind];

        int ans = 0;
        for(int i = ind+1; i<n; i++){
            if(abs(arr[i]-arr[ind]) == 1){
                ans = max(ans, 1+solve(i, arr, dp));
            }
        }
        return dp[ind] = ans;
    }
  public:
    int longestSubseq(vector<int> &arr) {
        // code here
        int n = arr.size();
        int ans = 0;

        vector<int> dp(n, -1);
        for(int i = 0; i<n; i++)
            ans = max(ans, 1+solve(i, arr, dp));
        
        return ans;
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
    cout<<obj.longestSubseq(arr);

    return 0;
}
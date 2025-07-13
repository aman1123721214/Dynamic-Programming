#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    string longestPalin (string str1) {
        // code here
        int n = str1.size();
        string str2 = "";
        for(int i = n-1; i>=0; i--)
        str2+=str1[i];

        vector<vector<int>> dp(n+1, vector<int>(n+1));
        for(int i = 0; i<n; i++){
            dp[i][0] = 0;
            dp[0][i] = 0;
        }
        int maxi = -1e9;
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=n; j++){
                if(str1[i-1]==str2[j-1]){
                    dp[i][j] = 1+dp[i-1][j-1];
                    maxi = max(maxi, dp[i][j]);
                }
                else dp[i][j] = 0;
            }
        }

        for(int i = 0; i<=n; i++){
            for(int j = 0; j<=n; j++)
                cout<<dp[i][j]<<" ";
                cout<<endl;
        }

        string ans = "";
        return ans;
    }
};

int main(){
    string str = "aaaabbaa";
    Solution obj;
    cout<<obj.longestPalin(str);
}
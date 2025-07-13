#include<bits/stdc++.h>
using namespace std;

class Solution{
  public:
    int findMinInsertion(string &s1){
        string s2 = s1;
        reverse(s2.begin(), s2.end());
        
        int n = s1.size();
        vector<vector<int>> dp(n+1, vector<int> (n+1, 0));
        
        for(int row = 0; row<=n; row++) dp[row][0] = 0;
        for(int col = 0; col<=n; col++) dp[0][col] = 0;
        
        int ans = 0;
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=n; j++){
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = 1+dp[i-1][j-1];
                    ans = max(ans, dp[i][j]);
                }
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]); 
            }
        }
        return n-ans;
    }
};

int main(){
    string str;
    getline(cin, str);

    Solution obj;
    cout<<obj.findMinInsertion(str);

    return 0;
}
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string longestPalindrome(string &s){
        //Code Here
        int n = s.size();
        string t = s;
        reverse(t.begin(), t.end());
        // cout<<t<<endl;

        vector<vector<int>> dp(n+1, vector<int> (n+1));
        for(int i = 0; i<=n; i++){
            dp[i][0] = 0;
            dp[0][i] = 0;
        } 

        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=n; j++){
                if(s[i-1] == t[j-1])
                    dp[i][j] = 1+dp[i-1][j-1];
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        // for(int i = 0; i<=n; i++){
        //     for(int j = 0; j<=n; j++){
        //         cout<<dp[i][j]<<" ";
        //     }cout<<endl;
        // }

        int len = dp[n][n];
        string temp = "";
        for(int i = 0; i<len; i++)temp+='$';
        int ind = len-1;

        int i = n, j = n;

        while(i>0 && j>0){
            if(s[i-1] == t[j-1]){
                temp[ind] = s[i-1];
                ind--;
                i--, j--;
            }
            else if(dp[i-1][j]>dp[i][j-1]) i--;
            else j--;
        }
        return temp;
    }
};

int main(){
    string str;
    getline(cin, str);
    Solution obj;

    cout<<obj.longestPalindrome(str);

    return 0;
}
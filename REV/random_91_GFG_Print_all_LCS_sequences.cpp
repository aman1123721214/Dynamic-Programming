#include<bits/stdc++.h>
using namespace std;

class Solution {
  private:int n, m;
    void LCS_Table(string &s1, string &s2, vector<vector<int>> &dp){
        //Code for preparation of dp matrix
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=m; j++){
                int len = 0;
                if(s1[i-1] == s2[j-1])
                    len = 1+dp[i-1][j-1];
                else len = max(dp[i][j-1], dp[i-1][j]);
                dp[i][j] = len;
            }
        }
    }

    void All_LCS(string a, string b, int i, int j, vector<vector<int>> dp, 
    string current, set<string>& result, map<string, set<string>> &memo){
        if(i==0 || j==0){
            reverse(current.begin(), current.end());
            result.insert(current);
            return;
        };
        
        string key = to_string(i)+"_"+to_string(j)+"_"+current;
        if(memo.find(key)!=memo.end()){
            result.insert(memo[key].begin(), memo[key].end());
            return;
        }
        
        set<string> localResult;
        
        if(a[i-1]==b[j-1]){
            current.push_back(a[i-1]);
                All_LCS(a,b,i-1,j-1,dp,current, localResult, memo);
            current.pop_back();
        }else{
            if (dp[i-1][j] == dp[i][j]) {
                All_LCS(a, b, i-1, j, dp, current, localResult, memo);
            }
            if (dp[i][j-1] == dp[i][j]) {
                All_LCS(a, b, i, j-1, dp, current, localResult, memo);
            }
        }
        
        memo[key] = localResult;
        result.insert(localResult.begin(), localResult.end());  
    }
  public:
    vector<string> all_longest_common_subsequences(string s, string t) {
        // Code here
        n = s.size(), m = t.size();
        //vector<string> ans;
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        map<string, set<string>> mp;
        set<string> st;

        LCS_Table(s, t, dp);
        All_LCS(s, t, n, m, dp, "", st, mp);

        return vector<string> (st.begin(), st.end());
    }
};

int main(){
    string s, t;    cin>>s>>t;

    cin>>s>>t;
    Solution obj;

    vector<string> lcs = obj.all_longest_common_subsequences(s, t);
    for(string str:lcs) cout<<str<<" ";

    return 0;
}
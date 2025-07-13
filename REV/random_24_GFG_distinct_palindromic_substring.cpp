#include<bits/stdc++.h>
using namespace std;

class Solution {
  private: int n;
    
    bool isPalind(string &s){
        int i = 0, j = s.size()-1;
        while(i<=j) if(s[i++] != s[j--]) return 0;
        return 1;
    } 

    void solve(int i, string &s, vector<bool> &dp, unordered_set<string> &st){
        if(i == n) return;
        
        if(dp[i]) return; 
        
        string temp = "";
        for(int k = i; k<n; k++){
            temp+=s[k];
            if(isPalind(temp)){
                st.insert(temp);    
                solve(k+1, s, dp, st);
            }
        }
        dp[i] = 1;
    }
  public:
    int palindromeSubStr(string &s){
        n = s.size();
        
        vector<bool> dp(n, 0);
        unordered_set<string> st;
        
        //sort(s.begin(), s.end());
        solve(0, s, dp, st);

        return st.size();
    }
};

int main(){
    string s;
    getline(cin, s);

    Solution obj;
    cout<<obj.palindromeSubStr(s);

    return 0;
}
#include<bits/stdc++.h>
using namespace std;

class Solution{
  private:
    int n;
    bool isPalind(string &str){
        int i = 0, j = str.size()-1;
        while(i<=j) if(str[i++] != str[j--]) return 0;
        return 1;
    }

    int solve(int i, string &s, vector<int> &dp){
        if(i>=n) return 0;
        if(dp[i] != -1) return dp[i];

        int mini = 1e9;
        string temp = "";

        for(int k = i; k<n; k++){
            temp+=s[k];
            if(isPalind(temp)) mini = min(mini, 1+solve(k+1, s, dp));
        }
        return dp[i] = mini;
    }
  public :
    int palindromePartion(string &s){
        n = s.size();
        vector<int> dp(n, -1);
        int ans = solve(0, s, dp);
        
        return ans == 1e9?0:ans ;
    }
};

int main(){
    string s;
    getline(cin, s);
    Solution obj;
    cout<<obj.palindromePartion(s);
    return 0;
}
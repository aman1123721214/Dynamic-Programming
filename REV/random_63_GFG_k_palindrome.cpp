#include<bits/stdc++.h>
using namespace std;

int lcs(string &s1, string &s2){
    int len = s1.size();
    vector<vector<int>> dp(len+1, vector<int>(len+1, 0));

    for(int i = 0; i<=len; i++)
        dp[i][0] = dp[0][i] = 0;
    
    for(int i = 1; i<=len; i++){
        for(int j = 1; j<=len; j++){
            if(s1[i-1] == s2[j-1])
                dp[i][j] = 1+dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[len][len];
}

bool iskPalindrome(string s, int k) {
    // code here
    int len = s.size();
    string temp = s;
    reverse(temp.begin(), temp.end());

    int palindLen = lcs(s, temp);
    return (len-palindLen) <= k;
}

int main(){
    cin.ignore();
    int k; cin>>k;

    string s;
    getline(cin, s);

    cout<<iskPalindrome(s, k);

    return 0;
}
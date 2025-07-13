#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class Solution {
  public:
    bool comparator(string &str1, string &str2){
        return str1.size()<str2.size();
    }
    static 
    bool checkPosiisble(string &str1, string &str2){
        if(str1.size() != str2.size()+1)    return 0;
        int i = 0, j = 0;
        while(i<str1.length()){
            if(j<str2.size() && str1[i] == str2[j])
                i++, j++;
            else    i++;
        }

        if(i == str1.length() && j == str2.length())    
            return 1;
        return 0;
    }

    int longestChain(int n, vector<string>& words) {
        // Code here
        vector<int> dp(n, 1);
        sort(words.begin(), words.end(), comparator);
        int maxi = 1;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<i; j++){
                if(checkPosiisble(words[i], words[j])
                && dp[i]<1+dp[j]){
                    dp[i] = 1+dp[j];
                    maxi = max(maxi, dp[i]);
                }
            }
        }return maxi;
    }
};
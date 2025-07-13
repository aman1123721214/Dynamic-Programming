#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    string longestPalin (string str1) {
        // code here
        int n = str1.length();
        String str2 = "";
        for(int i = n-1; i>=0; i--)
        str2+=str1.charAt(i);

        // System.out.println(str1);
        // System.out.println(str2);

        int maxi = 0;

        int dp[][] = new int[n+1][n+1];
        for(int i = 0; i<=n; i++){   
            dp[i][0] = 0;
            dp[0][i] = 0;
        }
        int r = 0;
        int c = 0;

        for(int i = 1; i<=n; i++){
            int ans = 0;
            for(int j = 1; j<=n; j++){
                if(str2.charAt(i-1)==str1.charAt(j-1)){
                    dp[i][j] = 1+dp[i-1][j-1];
                    ans = dp[i][j];
                    if(ans>maxi){
                        r = i;
                        c = j;
                        maxi = ans;
                    }
                }
                else dp[i][j] = 0;
            }
        }
        String ans = "";
        int len = maxi;
        if(len==1){
           ans+=str1.charAt(0);
           return ans;
        }

        while(len>0){
            if(str2.charAt(r-1)==str1.charAt(c-1)){
                ans+=str2.charAt(r-1);
                len--;
            }
            r--;c--;
        }
        return ans;
    }
};

int main(){
    string str = "aaaabbaa";
    Solution obj;
    cout<<obj.longestPalin(str);
}
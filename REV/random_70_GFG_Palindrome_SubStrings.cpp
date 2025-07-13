#include<bits/stdc++.h>
using namespace std;

class Solution {
  private:
    int solve(int i, int j, string &str){
        if(i<0 || j==str.length() || str[i] != str[j])
            return 0;
        if(j-i+1>1) return 1+solve(i-1, j+1, str);
        else return solve(i-1, j+1, str);
    }
  public:
    int countPS(string &str) {
        // code here
        int ans = 0;
        int n = str.length();

        for(int i = 0; i<n; i++){
            ans+=solve(i, i, str);
            if(i<n-1) ans+=solve(i, i+1, str);
        }
        return ans;
    }
};

int main(){
    string str;
    cin>>str;

    Solution obj;
    cout<<obj.countPS(str);

    return 0;
}
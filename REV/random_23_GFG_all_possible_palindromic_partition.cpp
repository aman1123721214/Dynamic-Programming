#include<bits/stdc++.h>
using namespace std;

class Solution{
  private: 
    int n;
    vector<vector<string>> vec2;
    
    bool isPalind(string &s){
        int i = 0, j = s.size();
        while(i<=j) if(s[i++] != s[j--]) return 0;
        return 1;
    }

    void solve(int i, string &s, vector<string> &vec1){
        if(i == n){
            vec2.push_back(vec1);
            return;
        }

        string temp = "";
        for(int k = i; k<n; k++){
            temp+=s[k];
            if(isPalind(temp)){
                vec1.push_back(temp);
                solve(k+1, s, vec1);
                vec1.pop_back();
            }
        }
    }
  public:
    vector<vector<string>> allPalindromeicPerms(string &s){
        n = s.size();
        
        vector<string> vec;
        solve(0, s, vec);
        
        return vec2;
    }
};

int main(){
    string s;
    cin>>s;

    Solution obj;
    vector<vector<string>> ans = obj.allPalindromeicPerms(s);

    for(auto it1: ans){
        for(auto it2:it1)
            cout<<it2;
        cout<<endl;
    } 
    return 0;
}
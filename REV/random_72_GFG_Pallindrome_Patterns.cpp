#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool isPalindrome(string s,int n){
        int i=0,j=n-1;
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;j--;
        }
        return true;
    }
    vector<string> all_plaindromes(string s){
        int n=s.length();
        vector<string> ans;
        string temp=s;
        do{
            if(isPalindrome(s,n)){
                ans.push_back(s);
            }
            next_permutation(s.begin(),s.end());
            
        }while(temp!=s);
        sort(ans.begin(),ans.end());
        return ans;
    }
};

int main(){
    string str;
    cin>>str;

    Solution obj;
    vector<string> ans = obj.all_plaindromes(str);

    for(string str: ans)
        cout<<str<<" ";
    
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

class Solution{
private:
    bool check(string str, unordered_map<string, bool> mp){
        while(str.length() != 0){
            if(mp.find(str) != mp.end())
                str.pop_back();
            else return 0;
        }
        return 1;
    }

public:
    string longestString(vector<string> &words) {
        // code here
        vector<string> temp = words;
        unordered_map<string, bool> mp;

        for(string str:words)
            mp[str] = 1;
        sort(temp.begin(), temp.end());

        string ans = "";
        int len = 0;

        for(string str:temp){
            if(check(str, mp)){
                if(str.length()>len || (str.length()==len && str<ans)){
                    len = str.length();
                    ans = str;     
                }
            }
        }
        return ans;
    }
};

int main(){
    int n;  cin>>n;
    vector<string> words(n);
    for(int i = 0; i<n; i++)
        cin>>words[i];
    
    Solution obj;
    cout<<obj.longestString(words);

    return 0;
}
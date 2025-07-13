#include <bits/stdc++.h>
using namespace std;

class Solution{
private:
    bool solve(int ind, string &str , set<string> &st){ 
        if(ind == str.length()) return 1;

        string temp = "";
        for(int i = ind; i<str.length(); i++){
            temp += str[i];
            if(st.find(temp) != st.end()){
                if(solve(i+1, str, st)) return 1;
            }
        }
        return 0;
    }
public:
    int wordBreak(int n, string s, vector<string> &dictionary) {
        //code here
        set<string> st(dictionary.begin(), dictionary.end());
        return solve(0, s, st);
    }


/************************* MEMOIZATION ******************************* */
// private:
//     bool solve(string s, string str, int ind, int n, 
//     vector<string> &dict, unordered_map<int, unordered_map<string, bool>> &dp){
//         if(str == s) return 1;
//         if(ind>n) return 0;
        
//         if(dp.count(ind) && dp[ind].count(str)) 
//             return dp[ind][str];

//         bool take = solve(s, str+dict[ind], ind+1, n, dict, dp);
//         bool nTake = solve(s, str, ind+1, n, dict, dp);

//         return dp[ind][str] = take || nTake;
//     }
// public:
//     int wordBreak(int n, string s, vector<string> &dictionary) {
//         //code here
//         unordered_map<int, unordered_map<string, bool>> dp;
//         sort(dictionary.begin(), dictionary.end());
//         return solve(s, "", 0, n, dictionary, dp);
//     }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dictionary;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dictionary.push_back(S);
        }
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.wordBreak(n, s, dictionary)<<"\n";
    
cout << "~" << "\n";
}
}

// } Driver Code Ends
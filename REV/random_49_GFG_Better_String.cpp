#include<bits/stdc++.h>
using namespace std;

class Solution {
  private:
    long long solve(string &s){
        int n = s.size();
        vector<long long> dp(n+1);
        unordered_map<char, int> last;

        dp[0] = 1;
        for(int i = 1; i<=n; i++){
            dp[i] = 2*dp[i-1];

            if(last.find(s[i-1]) != last.end())
                dp[i] -= dp[last[s[i-1]]];
            last[s[i-1]] = i-1;
        }
        return dp[n]-1;
    }
  public:
    string betterString(string str1, string str2) {
        // code here
        long long len1 = solve(str1);
        long long len2 = solve(str2);

        return (len1>=len2)?str1:str2;
    }


    /*************************** RECURSION **************************** */
//  TC = O(2^N) SC = O(N!)
    //   private: unordered_set<string> st;
//   int n;
//   void solve(int i, string temp, string &s){
//         if(i == n) {
//             st.insert(temp);
//             return;
//         }

//         st.insert(temp);

//         //take
//         solve(i+1, temp+s[i], s);
//         //ntake
//         solve(i+1, temp, s);
//   }
//   public:
//     string betterString(string str1, string str2) {
//         // code here
//         n = str1.size();
//         string temp = "";
//         solve(0, temp, str1);
//         int len1 = st.size();

//         st.clear();
//         n = str2.size();
//         solve(0, temp, str2);
//         int len2 = st.size();

//         return len1>=len2?str1:str2;
//     }
};

int main(){
    string str1, str2;
    getline (cin, str1);
    getline(cin, str2);

    Solution obj;
    cout<<obj.betterString(str1, str2);

    return 0;
}
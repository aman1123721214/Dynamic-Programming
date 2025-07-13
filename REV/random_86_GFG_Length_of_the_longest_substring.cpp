#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int longestUniqueSubstring(string &str) {
            if (str.empty()) {
                return 0;
            }
    
            unordered_map<char, int> mp;
    
            int maxLength = 0; 
            int i = 0;         
    
            for (int j = 0; j < str.length(); j++) {
                char currentChar = str[j];
    
                if (mp.find(currentChar) != mp.end() && mp[currentChar] >= i) 
                    i = mp[currentChar] + 1;
                
                mp[currentChar] = j;
                maxLength = max(maxLength, j - i + 1);
            }
            return maxLength;
        }
    };



// class Solution {
//   public:
//     int longestUniqueSubstring(string &str) {
//         // code
//         int len = 0;
//         int j = 0, i = 0;
        
//         unordered_map<char, bool> mp;

//         while(j<str.length()){
//             if(i == j || mp.find(str[j]) == mp.end()){
//                 mp[str[j]] = 1;
//                 len = max(len, j-i+1);
//                 j++;
//             }
//             else{
//                 mp.clear();
//                 i = j;
//             }
//         }
//         return len;
//     }
// };

int main(){
    string str;
    getline(cin, str);
    Solution obj;
    cout<<obj.longestUniqueSubstring(str);

    return 0;
}
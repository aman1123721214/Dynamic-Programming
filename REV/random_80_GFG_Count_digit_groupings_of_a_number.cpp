#include<bits/stdc++.h>
using namespace std;

class Solution{
  private:int n;
    unordered_map<string, int> mp;
    int solve(int preSum, int ind, string &str){
        if(ind == n) return 1;
        string key = to_string(preSum)+","+to_string(ind);

        if(mp.find(key) != mp.end()) return mp[key];

        int sum = 0, total = 0;
        for(int i = ind; i<n; i++){
            sum += str[i]-'0';

            if(sum>=preSum)
                total += solve(sum, i+1, str);
        }
         return mp[key] = total;
    }
  public:
	int TotalCount(string str){
	    // Code here
        n = str.size();
        return solve(0, 0, str);
	}
};

int main(){
    string str;
    cin>>str;

    Solution obj;
    cout<<obj.TotalCount(str);

    return 0;
}
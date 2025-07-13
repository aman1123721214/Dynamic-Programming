#include<bits/stdc++.h>
using namespace std;

int mod = 1e9+7;
class Solution{
  private:
    int solve(int i, int j, string &s1, string &s2){
        if(j<0) return 1;
        if(i<0) return 0;

        if(s1[i] == s2[j]){
            int take = solve(i-1, j-1, s1, s2);
            int nTake = solve(i-1, j, s1, s2);
            return take+nTake;
        }
        else return solve(i-1, j, s1, s2);
    }
  public:
	int TotalWays(string str){
	    // Code here
        string s = "GKS";
        int n = str.length(), m = s.length();
        return solve(n-1, m-1, str, s);
	}
};

int main(){
    string str;
    cin>>str;

    Solution obj;
    cout<<obj.TotalWays(str);

    return 0;
}
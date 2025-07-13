#include<bits/stdc++.h>
using namespace std;

class Solution{
  private:int l, r;
    int solve(int i, int j, string &word){
        if(i<l || j>r || word[i] != word[j]) return 0;
        return 1+solve(i-1, j+1, word);
    }
  public:
    int countPalinInRange (int n, string A, int q1, int q2) {
        // your code here
        int ans = 0;
        if(q1<q2)
            l = q1, r = q2;
        else l = q2, r = q1;
        
        for(int i = l; i<=r; i++){
            ans+=solve(i, i, A);
            if(i<r) ans+=solve(i, i+1, A);
        }
        return ans;
    }
};

int main(){
    string str;
    cin>>str;

    int q1, q2, n;
    cin>>q1>>q2>>n;


    Solution obj;
    cout<<obj.countPalinInRange(n, str, q1, q2);
}
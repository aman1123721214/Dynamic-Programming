#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string findMax(string N) {
        // code here
        sort(N.begin(), N.end());
        reverse(N.begin(), N.end());
        return N;
    }
};

int main(){
    string N;
    cin>>N;

    Solution obj;
    cout<<obj.findMax(N);

    return 0;
}
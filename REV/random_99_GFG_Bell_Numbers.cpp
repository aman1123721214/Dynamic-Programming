#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int bellNumber(int n) {
        // Code Here
        vector<int> prev(14), curr(14);
        prev[0] = 1;

        for(int i = 2; i<=n; i++){
            curr[0] = prev[i-2];
            for(int j = 1; j<i; j++)
                curr[j] = prev[j-1]+curr[j-1];
            prev = curr;
        }
        return prev[n-1];
    }
};

int main(){
    int n;  cin>>n;
    Solution obj;
    cout<<obj.bellNumber(n);

    return 0;
}
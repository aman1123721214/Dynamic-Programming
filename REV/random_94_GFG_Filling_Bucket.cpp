#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int fillingBucket(int N) {
        // code here
        int mod = 1e8;
        long long prev2 = 0, prev1 = 1;
        long long curr;

        for(int i = 2; i<=N+1; i++){
            curr = (prev2+prev1)%mod;
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};

int main(){
    int N;  cin>>N;
    Solution obj;
    cout<<obj.fillingBucket(N);

    return 0;
}
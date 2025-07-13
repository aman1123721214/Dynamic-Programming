#include<bits/stdc++.h>
using namespace std;

int mod = 1e9+7;
class Solution {
  public:
    int nCr(int n, int r) {
        // code here
        if(n<r) return 0;
        int _r = min(r, n-r);
        long long num = 1, den = 1;

        for(int i = 0; i<_r; i++){
            num = (num*1LL*(n-i))%mod ;
            den = (den*1LL*(_r-i))%mod;
        }
        return ((num*1LL)%mod)/((den*1LL)%mod);
    }
};

/*
 const int mod = 1e9+7;
    int binaryexp(int x, int n) {
        if(n == 0) return 1;
        int temp = binaryexp(x, n/2);
        if(n%2 == 0) return (1LL *temp * temp)%mod;
        else return (((1LL*temp*temp)%mod)*x)%mod;
    }
*/
int main(){
  int n, r;
  cin>>n>>r;
  Solution obj;
  cout<<obj.nCr(n, r);
}
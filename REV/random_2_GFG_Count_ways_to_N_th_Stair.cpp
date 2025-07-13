#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to count number of ways to reach the nth stair
    // when order does not matter.
    long long countWays(int n) {
        // your code here
        return n/2+1;
    }
};

int main(){
  int n; cin>>n;
  Solution obj;
  cout<<obj.countWays(n);
  return 0;
}
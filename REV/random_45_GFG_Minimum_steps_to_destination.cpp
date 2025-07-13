#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minSteps(int d) {
        // code here
        int sum = 0;
        int Stepcount = 0;

        while(sum != d){
            sum+=Stepcount;
            if(sum == d) return Stepcount;

            else if (sum>d){
                int temp = sum-d;
                if(!(temp%2)) break;
            }
            Stepcount++;
        }
        return Stepcount;
    }
};

int main(){
    int n; cin>>n;
    Solution obj;
    cout<<obj.minSteps(n);
    return 0;
}
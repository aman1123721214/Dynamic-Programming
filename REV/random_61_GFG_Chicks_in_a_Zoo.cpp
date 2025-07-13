#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        long long int NoOfChicks(int n){
            // Code here
            long long int sum = 1;
            long long int life[6]  = {1};

            for(int i = 1; i<n; i++){
                if(i>=6) sum-=life[i%6];
                life[i%6] = sum*2;
                sum+=life[i%6];
            }
            return sum;
        }
};

int main(){
    int n; cin>>n;
    Solution obj;
    cout<<obj.NoOfChicks(n);
    return 0;
}
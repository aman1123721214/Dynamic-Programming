#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int totalWays(int n, vector<int>capacity) {
        // code here
        int mod = 1e9+7;
        long long prod = 1;
        sort(capacity.begin(), capacity.end());

        for(int i = 0; i<n; i++){
            long long choices = max(0, capacity[i]-i);
            if(!choices) return 0;

            prod = (prod*choices)%mod;
        }
        return prod;
    }
};

int main(){
    int n;  cin>>n;
    vector<int> capacity(n);
    for(int i = 0; i<n; i++)    cin>>capacity[i];

    Solution obj;
    cout<<obj.totalWays(n, capacity);

    return 0;
}

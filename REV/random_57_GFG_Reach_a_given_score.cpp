#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    // Complete this function
    long long int count(long long int n){
    	// Your code here
        int score[] = {3, 5, 10};
        vector<long long int> dp(n+1, 0); 
        dp[0] = 1; 
        for (int i = 0; i < 3; i++) {
            for (int j = score[i]; j <= n; j++) {
                dp[j] += dp[j - score[i]];
            }
        }
        return dp[n];
    }
};

int main(){
    long long int n;
    cin>>n;

    Solution obj;
    cout<<obj.count(n);

    return 0;
}
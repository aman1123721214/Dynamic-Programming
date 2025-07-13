#include<bits/stdc++.h>
using namespace std;
class Solution{
    public :
    int NumberofLIS(int n, vector<int>&nums) {
        // Code here
        vector<int> dp(n, 1), count(n, 1);
        int maxi = 1;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<i; j++){
                if(nums[i]>nums[j] && 1+dp[j]>dp[i]){
                    dp[i] = 1+dp[j];
                    count[i] = count[j];
                }
                else if(nums[i]>nums[j] && 1+dp[j] == dp[i])
                    count[i]+=count[j];
                maxi = max(maxi, dp[i]);
            }
        }
        
        int ans = 0;
        for(int i = 0; i<n; i++)
        if(dp[i] == maxi) ans+=count[i];

        return ans;
    }
};

int main(){
    int n; cin>>n;
    vector<int> arr(n);
    for(int i = 0; i<n; i++)
    cin>>arr[i];

    Solution obj;
    cout<<obj.NumberofLIS(n, arr);
    return 0;
}
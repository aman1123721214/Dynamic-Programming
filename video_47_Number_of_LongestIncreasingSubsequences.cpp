#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int findNumberOfLIS(vector<int> &arr){
    // Write your code here.
    int n = arr.size();
    //if(n == 1) return 1;
    int maxi = 1;
    vector<int> dp(n, 1), cnt(n, 1);

    for(int i = 0; i<n; i++){
        for(int j = 0; j<i; j++){
            
            if(arr[j]<arr[i] && dp[i]<1+dp[j]){
                dp[i] = 1+dp[j];
                cnt[i] = cnt[j];
            }
            else if(arr[j]<arr[i] && dp[i] == 1+dp[j]){
                dp[i] = 1+dp[j];
                cnt[i] += cnt[j];
            }
        }maxi = max(maxi, dp[i]);
    }
    int ans = 0;
    for(int i = 0; i<n; i++){
        if(dp[i] == maxi) ans+=cnt[i];
    }
    return ans;
}

int main(){
    int n; cin>>n;
    vector<int> arr(n, 0);
    for(int i = 0; i<n; i++) cin>>arr[i];
    cout<<findNumberOfLIS(arr);
    return 0;
}
// #include<isotream>
// #include<bits/stdc++.h>
// using namespace std;
// int minSubsetSumDifference(vector<int>& nums, int n){
//         int sum=0;
//         for(auto it:nums) sum+=it;
//         int k=sum;
//         vector<vector<bool>>dp(n,vector<bool>(sum+1,0));
//         for(int i=0;i<n;i++) dp[i][0]=true;
//         if(nums[0]<=k) dp[0][nums[0]]=true;

//         for(int i=1;i<n;i++){
//             for(int j=1;j<=(k+1)/2;j++){
//                 bool notTake=dp[i-1][j];
//                 bool take=false;
//                 if(nums[i]<=j)
//                     take=dp[i-1][j-nums[i]];
//                 dp[i][j] = take || notTake;
//             }
//         }
//         int ans=1e9;
//         for(int s1=0;s1<=sum/2;s1++){
//             if(dp[n-1][s1]==true)
//             ans=min(ans,abs((sum-s1)-s1));
//         }return ans;
// }

// int main(){
//     int n;
//     vector<int> arr(n);
//     cin>>n;
//     for(int i = 0; i<n; i++){
//         cin>>arr[i];
//     }
//     cout<<minSubsetSumDifference(arr, n);
// }
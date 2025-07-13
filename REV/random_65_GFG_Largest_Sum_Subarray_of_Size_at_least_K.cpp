#include<bits/stdc++.h>
using namespace std;

class Solution{
  private:
    
  public:    
    long long int maxSumWithK(long long int a[], long long int n, 
        long long int k){
            //kadane's algo to find maxSum subArray till index "i"
            vector<long long int> maxSum(n);
            long long int currSum = 0;
            long long int maxi = LLONG_MIN;
            for(int i = 0; i<n; i++){
                currSum += a[i];
                maxi = max(a[i], currSum);
                maxSum[i] = maxi;

                if(currSum<0) currSum = 0;
            }

            long long int sum = 0;
            for(int i = 0; i<k; i++)
                 sum += a[i];
            
            long long int ans =  sum;
            for(int i = k; i<n; i++){
                sum += a[i] - a[i-k];
                ans = max(ans,  sum);  //window size == k
                ans = max(ans,  sum+maxSum[i-k]); //window size > k
            }
            return ans;
    }
};

int main(){
    long long int n, k; cin>>n>>k;
    
    long long int *arr = new long long int[n];
    for(int i = 0; i<n; i++)
        cin>>arr[i];

    Solution obj;
    cout<<obj.maxSumWithK(arr, n, k);

    return 0;
}
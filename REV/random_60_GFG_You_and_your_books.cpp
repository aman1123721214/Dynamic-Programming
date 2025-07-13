#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    long long max_Books(int arr[], int n, int k) {
        // Your code here
        long long ans = 0;
        long long sum = 0;

        for(int i = 0; i<n; i++){
            if(arr[i]>k){
                sum = 0;
                continue;
            }
            sum+=arr[i];
            ans = max(ans, sum);
        }
        return ans;
    }
};

int main(){
    int n, k;
    cin>>n>>k;

    int *arr = new int[n];
    for(int i = 0; i<n; i++) cin>>arr[i];

    Solution obj;
    cout<<obj.max_Books(arr, n, k);

    return 0;
}
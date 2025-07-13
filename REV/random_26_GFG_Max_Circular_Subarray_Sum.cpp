#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // arr: input array
    // Function to find maximum circular subarray sum.
    int circularSubarraySum(vector<int> &arr) {
        // your code here
        int n = arr.size();
        int maxi = -1e9, mini = 1e9, temp_mini = 0, 
        temp_maxi = 0, sum = 0;

        for(int i = 0; i<n; i++){
            temp_maxi += arr[i];
            maxi = max(maxi, temp_maxi);
            if(temp_maxi<0) temp_maxi = 0;

            temp_mini +=arr[i];
            mini = min(mini, temp_mini);
            if(temp_mini>0) temp_mini = 0;

            sum+=arr[i];
        }
        return max(maxi, sum-mini);
    }
};

int main(){
    string str;
    getline(cin, str);
    stringstream ss(str);
    
    int num;
    vector<int> arr;
    while(ss>>num) arr.push_back(num);

    Solution obj;
    cout<<obj.circularSubarraySum(arr);

    return 0;
}
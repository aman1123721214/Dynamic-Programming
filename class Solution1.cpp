#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
	void solve(int ind, int target, int *arr, int &count){
        if(target<0 || ind<0)    return;
        if(target==0){
            count++;
            return;
        }

        solve(ind-1, target, arr, count);    //nTake
        solve(ind-1, target-arr[ind], arr, count);    //take

        return;
    }
	int perfectSum(int arr[], int n, int sum){
        // Your code goes here
		int count = 0; 
		solve(n-1, sum, arr, count);
        return count;
	}
};

int main(){
    int n;
    cin>>n;
    int arr[n];

    for(int i = 0; i<n; i++)
        cin>>arr[i];
    int target; cin>>target;
    Solution obj;
    cout<<obj.perfectSum(arr, n, target);
}
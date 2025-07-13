#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {

  public:
    void findcombinations(int idx, int target, vector<int>& arr,
        vector<int>& ds, vector<vector<int>>& ans) {
            if (idx == arr.size()) {
            if (target == 0)
            ans.push_back(ds);
            return;
        }

        // picked up element
        if (arr[idx] <= target) {
            ds.push_back(arr[idx]);
            findcombinations(idx + 1, target - arr[idx], arr, ds, ans);
            ds.pop_back();
        }

        while (idx + 1 < arr.size() && arr[idx] == arr[idx + 1]) 
            idx++;

        findcombinations(idx + 1, target, arr, ds, ans);
    }

    vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
        vector<int> ds;

        vector<vector<int>> ans;
        sort(arr.begin(), arr.end());
        findcombinations(0, target, arr, ds, ans);

        return ans;
    }

};

int main(){
    Solution obj;
    int n; cin>>n;
    vector<int> nums(n);
    for(int i = 0; i<n; i++)
    cin>>nums[i];

    int target; cin>>target;
    vector<vector<int>> vec = obj.combinationSum2(nums, target);
    for(auto it1: vec){
        for(auto it2: it1)
        cout<<it2<<" ";
        cout<<endl;
    }
    return 0;
}
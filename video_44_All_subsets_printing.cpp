#include<bits/stdc++.h>
#include<iostream>
using namespace std;
class Solution {
    public: vector<vector<int>> ans;
            set<vector<int>> st;
    
    void solve(int ind, vector<int> &nums, vector<int> v1){

        if(ind == nums.size()){
            sort(v1.begin(), v1.end());

            st.emplace(v1);
            return;
        }

        v1.push_back(nums[ind]);   //take
        solve(ind+1, nums, v1);
        
        v1.pop_back();
        solve(ind+1, nums, v1);   //nTake
    }

  public:
    vector<vector<int>> printUniqueSubsets(vector<int>& nums) {
        // Write your code here
        vector<int> vec;
        solve(0, nums, vec);

        for(auto it: st){
            ans.push_back(it);
        }
        st.clear();

        return ans;
    }
};

int main(){
    Solution obj;
    int n; cin>>n;
    vector<int> nums(n);
    for(int i = 0; i<n; i++)
    cin>>nums[i];

    vector<vector<int>> vec = obj.printUniqueSubsets(nums);
    for(auto it1: vec){
        for(auto it2: it1)
        cout<<it2<<" ";
        cout<<endl;
    }
    return 0;
}
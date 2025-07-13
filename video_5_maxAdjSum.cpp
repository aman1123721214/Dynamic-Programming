// #include<iostream>
// #include<bits/stdc++.h>
// using namespace std;

/******************************** MEMOIZATION ************************************************ */
// int solve(vector<int> &nums, int idx, vector<int> &dp){
//     if(idx == 0) return nums[idx];
//     if(idx < 0) return 0;
//     if(dp[idx] != -1) dp[idx];

//     int pick = nums[idx]+solve(nums, idx-2, dp);
//     int nPick = solve(nums, idx-1, dp);

//     return dp[idx] = max(pick, nPick);
// }


// int nonadjacentSum(vector<int> &nums){
//     int idx = nums.size()-1;
//     vector<int> dp(idx+1, -1);
//     return solve(nums, idx, dp);
// }

/******************** MAX SPACE OPTIMIZATION ****************************************************/
// int nonadjacentSum(vector<int> &nums){
//     int n = nums.size();
//     int prev = nums[0], prev2 = 0;

//     for(int i = 1; i<n; i++){
//         int take = nums[i];
//         if(i>1) take+=prev2;

//         int ntake = prev;
//         int curr = max(take, ntake);
//         prev2 = prev;
//         prev = curr;
//     }
//     return prev;
// }

/**************************************** MAIN ************************************************** */
// int main(){
//     int element, size;
//     vector<int> nums;

//     cout<<"enter size of the array:";
//     cin>>size;

//     cout<<"enter the elements in the array: ";
//     for(int i = 0; i<size; i++){
//         cin>>element;
//         nums.push_back(element);
//     }

//     cout<<"max adjacent sum = "<<nonadjacentSum(nums);
// }

// #include<iostream>
// #include<bits/stdc++.h>
// using namespace std;

/****************************************** USING BINARY SEARCH ******************************************** */

// int longestIncreasingSubsequence(int arr[], int n){
//     // Write Your Code here
//     vector<int> temp;
//     temp.push_back(arr[0]);
//     int len = 1;
//     for(int i = 1; i<n; i++){
//         if(arr[i]>temp.back()){
//             temp.push_back(arr[i]);
//             len++;
//         }
//         else {
//             int ind = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
//             temp[ind] = arr[i];
//        }
//     }return temp.size();
// }

// int main(){
//     int n; cin>>n;
//     int *arr = new int[n];              //taking array dynamically
//     for(int i = 0; i<n; i++) cin>>arr[i];
//     cout<<longestIncreasingSubsequence(arr, n);
//     return 0;
// }
#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int solve(int front, int end, vector<int> &arr,
     vector<vector<int>> &dp){
        if(front > end) return 0;

        if(dp[front][end] != -1) return dp[front][end];

        int x = arr[front]+min(solve(front+1, end-1, arr, dp), solve(front+2, end, arr, dp));
        int y = arr[end]+min(solve(front+1, end-1, arr, dp), solve(front, end-2, arr, dp));

        return dp[front][end] = max(x, y);

    }
public:
    int maxCoins(vector<int>&A,int n){
	    //Write your code here
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return solve(0, n-1, A, dp);
    }
};

int main(){
    int n; cin>>n;
    cin.ignore();
    
    string str;
    getline(cin, str);
    stringstream ss(str);

    int num;
    vector<int> ip;
    while(ss>>num) ip.push_back(num);

    Solution obj;
    cout<<obj.maxCoins(ip, n);

    return 0;
}
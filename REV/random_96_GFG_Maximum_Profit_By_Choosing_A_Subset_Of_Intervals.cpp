#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maximum_profit(int n, vector<vector<int>> &intervals) {
        // Write your code here.
        sort(intervals.begin(), intervals.end(), 
        [&](vector<int> &a, vector<int> &b){
            return (a[1]<b[1]);
        });

// cout<<"******************************************"<<endl;
//         for(auto it:intervals){
//             for(int it1:it)
//                 cout<<it1<<" ";
//             cout<<endl;
//         }
        
        vector<int> dp(n, 0);
        dp[0] = intervals[0][2];

        for(int i = 1; i<n; i++){
            dp[i] = dp[i-1];

            int j = i-1;
            while(j>=0 && intervals[j][1]>intervals[i][0])
                j--;
            if(j>=0) dp[i] = max(dp[i], dp[j]+intervals[i][2]);
            else dp[i] = max(dp[i], intervals[i][2]);
        }
        return dp[n-1];
    }
};
// class Solution {
//   private:unordered_map<string, int> mp;
//     int solve(int e, int ind, vector<vector<int>> &dp,
//          vector<vector<int>> &intervals){
//             int n = intervals.size();
            
//             if(ind == n) return 0;
//             if(dp[e][ind] != -1) return dp[e][ind];

//             int points = 0;
//             for(int i = ind; i<n; i++){
//                 int st = intervals[i][0];
//                 int end = intervals[i][1];

//                 if(st>=e)
//                     points+=intervals[i][2] + solve(end, i+1, dp, intervals);
//             }
//             return dp[e][ind] = points;
//     }
//   public:
//     int maximum_profit(int n, vector<vector<int>> &intervals) {
//         // Write your code here.
//         sort(intervals.begin(), intervals.end());
//         for(int i = 0; i<n; i++)
//             cout<<intervals[i][0]<<" "<<intervals[i][1]<<" "<<intervals[i][2];
        
//         int et = 0;
//         for(int i = 0; i<n; i++)
//             et = max({et, intervals[i][0], intervals[i][1]});

//         vector<vector<int>> dp(et+1, vector<int>(n+1, -1));

//         int maxi = 0;
//         for(int i = 0; i<n; i++)
//             maxi = max(maxi, solve(-1, i, dp, intervals));
        
//         return maxi;
//     }
// };

int main(){
    int n;  cin>>n;

    vector<vector<int>> intervals(n, vector<int> (3, 0));

    for(int i = 0; i<n; i++)
        cin>>intervals[i][0]>>intervals[i][1]>>intervals[i][2];
    
    Solution obj;
    cout<<obj.maximum_profit(n, intervals);

    return 0;
}
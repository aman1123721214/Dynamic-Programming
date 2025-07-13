#include<bits/stdc++.h>
using namespace std;

class Solution{
    private:
    int ans = 0;
    vector<vector<vector<int>>> dp;
    //unordered_map<int, unordered_map<int, unordered_map<int, int>>> dp;
        void solve(int h, int m, int prev, int level){
            if(m<=0 || h<=0) return ;

            if(dp[h][m][prev] != -1){
                //ans = /*max(ans, */dp[h][m][prev];
                return;
            }
            
            for(int road = 0; road<3; road++){
                if(road != prev){
                    if(road == 0) solve(h-20, m+5, 0, level+1);
                    if(road == 1) solve(h-5, m-10, 1, level+1);
                    if(road == 2) solve(h+3, m+2, 2, level+1);
                }
            }
            ans = max(ans, level);
            dp[h][m][prev] = ans;
        }
    public:
        int maxLevel(int h,int m){
            // code here
            dp = vector<vector<vector<int>>>
            (801, vector<vector<int>>
            (801, vector<int>(4, -1)));

            solve(h, m, 3, 0);
            return ans;
        }


    // private:
    // int ans = 0;
    //     void solve(int h, int m, int prev, int level){
    //         if(m<=0 || h<=0) return;

    //         for(int road = 0; road<3; road++){
    //             if(road != prev){
    //                 if(road == 0) solve(h-20, m+5, 0, level+1);
    //                 if(road == 1) solve(h-5, m-10, 1, level+1);
    //                 if(road == 2) solve(h+3, m+2, 2, level+1);
    //             }
    //         }
    //         ans = max(ans, level);
    //     }
    // public:
    //     int maxLevel(int h,int m){
    //         // code here
    //         solve(h, m, 3, 0);
    //         return ans;
    //     }
};

int main(){
    int h, m; cin>>h>>m;
    Solution obj;
    cout<<obj.maxLevel(h, m);
}
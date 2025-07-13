#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    unordered_map<int, bool> stoneMap;
    unordered_map<int, unordered_map<int, bool>> dp; 

    bool solve(int currPos, int prevJump, vector<int>& stones) {
        // base cases
        if (currPos == stones.back()) return true; 
        if (prevJump <= 0 || !stoneMap[currPos]) return false;
        if (dp[currPos].count(prevJump)) return dp[currPos][prevJump];

        bool canCross = solve(currPos + prevJump - 1, prevJump - 1, stones) ||
                        solve(currPos + prevJump, prevJump, stones) ||
                        solve(currPos + prevJump + 1, prevJump + 1, stones);

        return dp[currPos][prevJump] = canCross;
    }

public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        for (int i = 0; i < n; i++) 
            stoneMap[stones[i]] = true;
        
        if (!stoneMap[1]) return false;

        return solve(1, 1, stones);
    }
};

int main(){
    string tc;
    getline(cin, tc);
    int t = stoi(tc);
    while(t--){
        string str;
        getline(cin, str);
        stringstream ss(str);

        int num;
        vector<int> arr;
        while(ss>>num) arr.push_back(num);

        Solution obj;
        cout<<obj.canCross(arr);

    }
    return 0;
} 
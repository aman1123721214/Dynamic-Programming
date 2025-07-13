#include<bits/stdc++.h>
using namespace std;

class Solution {
  private:
  public:
    int lengthOfLongestAP(vector<int>& arr) {
        // code here
        int n = arr.size();
        if(n <= 1) return n;
        
        vector<unordered_map<int, int>> dp(n);
        int maxLength = 2;

        for(int i = 0; i<n; i++){
            for(int j = i+1; j<n; j++){
                int d = arr[j]-arr[i];

                dp[j][d] = dp[i].count(d)?dp[i][d]+1:2;
                maxLength = max(maxLength, dp[j][d]);
            }
        }
        return maxLength;
    }
};

int main(){
    string str;
    getline(cin, str);
    stringstream ss(str);

    int num;
    vector<int> arr;
    while(ss>>num)
    arr.push_back(num);

    Solution obj;
    cout<<obj.lengthOfLongestAP(arr);

    return 0;
}


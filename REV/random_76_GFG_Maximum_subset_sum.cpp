#include<bits/stdc++.h>
using namespace std;

class Solution {
  private:
    long long solve(int ind, vector<int> &mat, vector<long long> &dp){
        if(ind<0) return 0;
        if(dp[ind] != -1) return dp[ind];

        long long take = mat[ind] + solve(ind-1, mat, dp);
        long long nTake = mat[ind] + solve(ind-2, mat, dp);

        return dp[ind] = max(take, nTake);
    }
  public:
    long long findMaxSubsetSum(int N, vector<int> &A) {
        // code here
        vector<long long> dp(N, -1);
        return max(solve(N-1, A, dp),solve(N-2, A, dp));
    }
};

int main(){
    int N;  cin>>N;
    vector<int> A(N);
    for(int i = 0; i<N; i++)
        cin>>A[i];
    
    Solution obj;
    cout<<obj.findMaxSubsetSum(N, A);

    return 0;
}
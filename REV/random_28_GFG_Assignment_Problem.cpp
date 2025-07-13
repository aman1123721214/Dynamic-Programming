#include<bits/stdc++.h>
using namespace std;

class Solution {
  private:
    int solve(int row, int prev, vector<bool> &job, vector<vector<int>> &arr){
        if(row<0) return 0;
        int n = arr.size();

        int ans = 1e9;
        int time = 0;
        job[prev] = 1;

        for(int i = 0; i<n; i++){
            if(!job[i]){
                job[i] = 1;
                time = arr[row][i]+solve(row-1, i, job, arr);
                job[i] = 0;
            }
        }

        time+=arr[row][prev];
        job[prev] = 0;
        return ans = min(ans, time);
    }
  public:
    int assignmentProblem(int arr[], int n) {
        // code here
        vector<bool> job(n, 0);
        vector<vector<int>> temp(n, vector<int>(n));
        int ind = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                temp[i][j] = arr[ind++];
            }
        }
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++)
                cout<<temp[i][j]<<" ";
            cout<<endl;
        }

        
        int ans = 1e9;
        for(int i = 0; i<n; i++)
        ans = min(ans, solve(n-1, i, job, temp));

        return ans;
    }
};

int main(){
    int n; cin>>n;
    int Arr[n*n];
    for(int i = 0; i<n*n; i++)
        cin>>Arr[i];
    
    Solution obj;
    cout<<obj.assignmentProblem(Arr, n);

    return 0;
}
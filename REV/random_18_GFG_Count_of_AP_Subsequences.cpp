#include<bits/stdc++.h>
using namespace std;

class Solution {
  private:
    int solve(int i, int d, vector<int> &arr){
        int n = arr.size();
        if(i == n) return 1;

        if(i+1<n && arr[i+1]-arr[i] == d) 
            return 1+solve(i+1, d, arr);
        else return solve(i+1, d, arr);
    }
  public:
    int count(vector<int>& arr) {
        // code here
        int n = arr.size();
        int count = 0;

        for(int i = 0; i<n; i++){
            for(int j = i; j<n; j++){
                int d = arr[j]-arr[i];
                if(d>0)
                    count+=solve(j, arr[j]-arr[i], arr);
            }
        }
        return count;
    }
};

int main(){
    string str;
    getline(cin, str);
    stringstream ss(str);

    vector<int> arr;
    int num;
    while(ss>>num)
        arr.push_back(num);

    Solution obj;
    cout<<obj.count(arr);
}
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int longestPerfectPiece(int arr[], int N) {
        // code here
        multiset<int> minSet;
        multiset<int, greater<int>> maxSet;

        int maxi = 0;
        int l = 0;

        for(int r = 0; r<N; r++){
            minSet.insert(arr[r]);
            maxSet.insert(arr[r]);

            while(!minSet.empty() && !maxSet.empty() && 
                *maxSet.begin()-*minSet.begin()>1){
                    minSet.erase(minSet.find(arr[l]));
                    maxSet.erase(maxSet.find(arr[l]));
                    
                    l++;
            }
            maxi = max(maxi, r-l+1);
        }
        return maxi;
    }
};

/*
ip = 11
5 4 5 5 6 7 8 8 8 7 6
op = 5
*/
int main(){
    int n; cin>>n;
    int *arr = new int[n];

    for(int i = 0; i<n; i++) cin>>arr[i];

    Solution obj;
    cout<<obj.longestPerfectPiece(arr, n);
}
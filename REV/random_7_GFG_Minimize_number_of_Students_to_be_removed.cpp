#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int removeStudents(int H[], int N) {
        // code here
        vector<int> temp;
        temp.push_back(H[0]);
        
        for(int i = 1; i<N; i++){
            if(temp.back()<H[i])
                temp.push_back(H[i]);
            else{
                int lb = lower_bound(temp.begin(), temp.end(), H[i])-temp.begin();
                temp[lb] = H[i];
            }
        }
        return N-temp.size();
    }
};

int main(){
    int n; cin>>n;
    
    int arr[n];
    for(int i = 0; i<n; i++) cin>>arr[i];
    
    Solution obj;
    cout<<obj.removeStudents(arr, n);

    return 0;
}
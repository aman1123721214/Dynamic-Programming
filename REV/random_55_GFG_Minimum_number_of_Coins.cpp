#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<int> minPartition(int N) {
        // code here
        int currency[]  = {2000,500,200,100,50,20,10,5,2,1};

        vector<int> ans;
        int i = 0;
        int notes = 0;
        
        while(N){
            notes = N/currency[i];
            while(notes--){
                ans.push_back(currency[i]);
            }
            N%=currency[i++];
        }
        return ans;
    }
};

int main(){
    int n; cin>>n;
    Solution obj;
    vector<int> ans = obj.minPartition(n);
    for(int it: ans) cout<<it<<" ";

    return 0;
}
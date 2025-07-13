#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int countSubstr(string& s, int k) {
        // code here.
        //return solve(0, 0, k, s);

        int n=s.size();
        int p=k;
        int q=k-1;
        int left=0,right=0,cnt=0;
        unordered_map<int,int> mpp;
        while(right<n){
            mpp[s[right]]++;
            while(mpp.size()>p){
                mpp[s[left]]--;
                if(mpp[s[left]]==0){
                    mpp.erase(s[left]);
                }
                left++;
            }
            cnt=cnt+(right-left+1);
            right=right+1;
        }
        unordered_map<int,int> mpp1;
        int left1=0,right1=0,cnt1=0;
        while(right1<n){
            mpp1[s[right1]]++;
            while(mpp1.size()>q){
                mpp1[s[left1]]--;
                if(mpp1[s[left1]]==0){
                    mpp1.erase(s[left1]);
                }
                left1++;
            }
            cnt1=cnt1+(right1-left1+1);
            right1=right1+1;
        }
        return cnt-cnt1;
    }
};

int main() {
    string s;
    cin >> s;
    int k;
    cin >> k;
    Solution ob;
    cout << ob.countSubstr(s, k) << endl;

    return 0;
}

/*
//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int countSubstr(string& s, int k) {
        // code here.
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.countSubstr(s, k) << endl;

        cout << "~"
             << "\n";
    }
}
// } Driver Code Ends
*/
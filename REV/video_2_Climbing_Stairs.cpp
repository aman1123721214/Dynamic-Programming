/*#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if(n<=2) return n;

        //return climbStairs(n-1)+climbStairs(n-2);

        int prev1 = 2;
        int prev2 = 1;
        int temp;

        for(int i = 3; i<=n; i++){
            temp = prev2+prev1;
            prev2 = prev1;
            prev1 = temp;
        }
        return prev1;
    }
};

int main(){
    int n;
    cin>>n;

    Solution obj;
    cout<<obj.climbStairs(n);
    
    return 0;
}
*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
  private:
  unordered_map<int, bool> stoneAt;
    bool solve(int ind, int jump, vector<int> &arr){
        if(ind+jump-1 == ind) return 0;
        if(ind == arr.back()) return 1;
        if(ind>arr.back()) return 0;
        if(!stoneAt[ind]) return 0;

        return solve(ind+jump, jump+1, arr) || solve(ind+jump-1, jump+1, arr) || solve(ind+jump+1, jump+1, arr);
                //k                                 //k-1                               //k+1               
    }
  public:
    bool canCross(vector<int> &arr){
        for(int it: arr) stoneAt[it] = 1;
        
        if(!stoneAt[1]) return 0;
        return solve(0, 0, arr)+solve(1, 1, arr)+solve(2, 1, arr);
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
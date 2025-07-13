#include<bits/stdc++.h>
using namespace std;

class Solution{
public:	
	int maxSubstring(string &str){
	    // Your code goes here
        int count = 0;
        int maxi = -1;

        for(int i = 0; i<str.size(); i++){
            if(str[i] == '0') count++;
            else count--;

            maxi = max(maxi, count);
            if(count<0) count = 0;
        }
        return maxi;
	}
};

int main(){
    string str;
    getline(cin, str);

    Solution obj;
    cout<<obj.maxSubstring(str);

    return 0;
}
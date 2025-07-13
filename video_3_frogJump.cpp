// #include<bits/stdc++.h>
// using namespace std;
//********************* MEMOIZATION *********************************
// int solve(int n, vector<int> &heights, vector<int> &dp){
//     if(n == 0) return 0;
//     if(dp[n] != -1) return dp[n];
//     int left = solve(n-1, heights, dp)+abs(heights[n]-heights[n-1]);
    
//     int right = INT_MAX;
//     if(n>1)
//     right = solve(n-2, heights, dp)+abs(heights[n]-heights[n-2]); 
    
//     return dp[n] = min(right, left);

// }

// int frogJump(int n, vector<int> &heights){
//     vector<int> dp(n+1, -1);
//     return solve(n-1, heights, dp);
// }

//********************* TABULATION *********************************

// int frogJump(int n, vector<int> &heights){
//     vector<int> dp(n, 0);
//     dp[0] = 0;
//     for(int i = 1; i<n; i++){
//         int fs = dp[i-1]+abs(heights[i]-heights[i-1]);
//         int ss = INT_MAX;
//         if(i>1)
//         ss = dp[i-2]+abs(heights[i]-heights[i-2]);

//         dp[i] = min(fs, ss);
//     }
//     return dp[n-1];
// }

//********************** MAX SPACE OPTIMIZATION ********************
// int frogJump(int n, vector<int> &heights){
//     int prev1 = 0, prev2 = 0, curr;

//     for(int i = 1; i<n; i++){
//         int fs = prev1+ abs(heights[i]-heights[i-1]);
//         int ss = INT_MAX;
        
//         if(i>1)
//         ss = prev2+ abs(heights[i]-heights[i-2]);
//         curr = min(fs, ss);

//         prev2 = prev1;
//         prev1 = curr;
//     }
//     return curr;
// }
//*********************************************************** */


// int main(){

//     int stairs, element;
//     vector<int> heights;
//     cout<<"enter the stairs: "<<endl;
//     cin>>stairs;

//     cout<<"enter the heights: "<<endl;
//     for(int i = 0; i<stairs; i++){
//         cout<<"heights "<<i+1<<"=";
//         cin>>element;
//         heights.push_back(element);
//     }
    
//     cout<<" min energy required :"<<frogJump(stairs, heights);
//     return 0;
// }
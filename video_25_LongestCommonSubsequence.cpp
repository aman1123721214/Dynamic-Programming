#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// int solve(int ind1, int ind2, string &str1, string &str2, vector<vector<int>> &dp){
//     if(ind1<0 || ind2<0) return 0;
//     if(dp[ind1][ind2] != -1) return dp[ind1][ind2];

//     if(str1[ind1] == str2[ind2]) 
//     dp[ind1][ind2] = 1+solve(ind1-1, ind2-1, str1, str2, dp);

//     else return  
//     dp[ind1][ind2] = max(solve(ind1-1, ind2, str1, str2, dp), solve(ind1, ind2-1, str1, str2, dp));
// }
// int lcs(string str1, string str2)
// {
// 	//Write your code here
//     int n = str1.size();
//     int m = str2.size();
//     vector<vector<int>> dp(n, vector<int> (m, -1));

//     int ans = solve(n-1, m-1, str1, str2, dp);

//     for(int i = 0; i<n; i++){
//         for(int j = 0; j<m; j++) cout<<dp[i][j];
//     }cout<<endl;
//     return ans;
// }

int lcs(string str1, string str2)
{
	//Write your code here
    int n = str1.size();
    int m = str2.size();
    vector<vector<int>> dp(n+1, vector<int> (m+1, 0));

    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=m; j++){
            if(str1[i-1] == str2[j-1]) dp[i][j] = 1+dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    for(int i = 0; i<=n; i++){
        for(int j = 0; j<=m; j++) cout<<" "<<dp[i][j];
        cout<<endl;
    }
    return dp[n][m];
}
int main(){
    string str1, str2;
    cin>>str1>>str2;
    cout<<lcs(str1, str2);
    return 0;
}
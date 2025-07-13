class Solution {
    constructor(){
        this.solve = this.solve.bind(this);
    }

    solve(i, j, str, dp){
        if(i>j) return 0;
        if(i === j) return 1;

        if(dp[i][j] != -1) return dp[i][j];

        if(str.charAt(i) === str.charAt(j))
            dp[i][j] = 1+this.solve(i+1, j, str, dp)+this.solve(i, j-1, str, dp);
        else dp[i][j] = this.solve(i+1, j, str, dp)+this.solve(i, j-1, str, dp)-this.solve(i+1, j-1, str, dp);
        return dp[i][j];
    }
    countPS(s) {
        // code here
        const n = s.length;
        const dp = Array.from({length:n}, () =>Array(n).fill(-1));
        return this.solve(0, n-1, s, dp);
    }
}
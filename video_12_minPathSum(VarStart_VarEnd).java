import java.util.Arrays;

class Solution{
//method 1: memoization
    // public static int solve(int row, int col, int n, int dp[][], int matrix[][]){
    //     if(col<0 || col>n-1 ) return (int) (-1e9);
    //     if(row==n-1) return dp[row][col] = matrix[row][col];
        
    //     if(dp[row][col] != -1) return dp[row][col];
        
    //     int down = matrix[row][col]+solve(row+1, col, n, dp, matrix);
    //     int ldg = matrix[row][col]+solve(row+1, col-1, n, dp, matrix);
    //     int rdg = matrix[row][col]+solve(row+1, col+1, n, dp, matrix);

    //     return dp[row][col] = Math.max(down, Math.max(ldg, rdg));
    // }

    // public static int maximumPath(int n, int matrix[][]){
    //     // code here
    //     int dp[][] = new int[n][n];
    //     for(int row[]: dp)
    //         Arrays.fill(row, -1);

    //     int ans = Integer.MIN_VALUE;
    //     for(int i = 0; i<n; i++){
    //         ans = Math.max(ans, solve(0, i, n, dp, matrix));
    //     }
    //     return ans;
    // }
//method 2: tabulation
    public static int maximumPath(int n, int matrix[][]){
        // code here
        int dp[][] = new int[n][n];
        for(int row[]: dp)
            Arrays.fill(row, -1);

        int ans = Integer.MIN_VALUE;
        dp[n-1] = matrix[n-1].clone();
        
        for(int row = n-2; row>=0; row--){
            for(int col = 0; col<n; col++){
                int down = matrix[row][col]+dp[row+1][col];

                int ldg = matrix[row][col];
                if(col>0)
                ldg+=dp[row+1][col-1];

                int rdg = matrix[row][col];
                if(col<n-1)
                rdg+=dp[row+1][col+1];

                dp[row][col] = Math.max(down, Math.max(ldg, rdg));
            }
        }

        for(int i = 0; i<n; i++)
            ans = Math.max(ans, dp[0][i]);
        return ans;
    }
}
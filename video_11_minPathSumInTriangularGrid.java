import java.util.ArrayList;
class video_11_minPathSumInTriangularGrid {
//method 1: memoization
    // public static int[][] dp;
    // public static int solve(int row, int col, int n, ArrayList<ArrayList<Integer> >grid){
    //     if(row==n-1) return dp[n-1][col] = grid.get(n-1).get(col);

    //     if(dp[row][col] != -1) return dp[row][col];

    //     int down = grid.get(row).get(col)+solve(row+1, col, n, grid);
    //     int diag = grid.get(row).get(col)+solve(row+1, col+1, n, grid);

    //     return dp[row][col] = Math.min(down, diag);
    // }

    // public static int minimizeSum(int n, ArrayList<ArrayList<Integer> >grid) {
    //     // Code here
    //     dp = new int[n][n];
    //     for(int i = 0; i<n; i++){
    //         for(int j = 0; j<n; j++)
    //             dp[i][j] = -1;
    //     }
    //     return solve(0, 0, n, grid);
    // }

//method 2: tabulation
    // public static int minimizeSum(int n, ArrayList<ArrayList<Integer> >grid) {
    //     // Code here
    //     int dp[][] = new int[n][n];
    //     for(int i = 0; i<n; i++){
    //         for(int j = 0; j<n; j++)
    //             dp[i][j] = -1;
    //     }

    //     for(int i = 0; i<n; i++){
    //         dp[n-1][i] = grid.get(n-1).get(i);
    //     }

    //     for(int i = n-2; i>=0; i--){
    //         for(int j = i; j>=0; j--){
    //             int down = grid.get(i).get(j)+dp[i+1][j];
    //             int diag = grid.get(i).get(j)+dp[i+1][j+1];
    //             dp[i][j] = Math.min(down, diag);
    //         }
    //     }
    //     return dp[0][0];
    // }
    public static int minimizeSum(int n, ArrayList<ArrayList<Integer> >grid) {
        // Code here
        int[] front = new int[n]; 
        int[] cur = new int[n];

        for (int j = 0; j < n; j++) {
            front[j] = grid.get(n-1).get(j);
        }

        for(int i = n-2; i>=0; i--){
            for(int j = i; j>=0; j--){
                int down = grid.get(i).get(j)+front[j];
                int diag = grid.get(i).get(j)+front[j+1];
                cur[j] = Math.min(down, diag);
            }front = cur.clone();
        }return front[0];
    }
}
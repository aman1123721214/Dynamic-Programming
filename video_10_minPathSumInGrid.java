import java.util.*;
class video_10_minPathSumInGrid{
    //Function to return the minimum cost to react at bottom
	//right cell from top left cell.
    public static int[][] dp, vis;
    public static int ans;

    public static void solve(int sr, int sc, int row ,int col, int[][] grid, int pathLen){
        if(sr==row && sc==col){
            ans = Math.min(ans, pathLen+grid[row][col]);
            return;
        }
        
        if(dp[sr][sc] != -1) {
            pathLen += dp[sr][sc];
            return;
        }
        
        vis[sr][sc] = 1;
        int drow[] = {1, -1, 0, 0};
        int dcol[] = {0, 0, 1, -1};

        for(int i = 0; i<4; i++){
            int nrow = sr+drow[i];
            int ncol = sc+dcol[i];

            if(nrow>=0 && nrow<=row && ncol>=0 && ncol<=col){
                if(vis[nrow][ncol] != 1)
                solve(nrow, ncol, row, col, grid, grid[row][col]+pathLen);
            }
        }
        vis[sr][sc] = 0;
        dp[sr][sc] = pathLen;
    }
    
    //Function to return the minimum cost to react at bottom
	//right cell from top left cell.
    public static int minimumCostPath(int[][] grid){
        // Code here
        int row = grid.length-1;
        int col = grid[0].length-1;
        ans = Integer.MAX_VALUE;

        vis = new int[row+1][col+1];
        for(int i = 0; i<=row; i++){
            for(int j = 0; j<=col; j++)
                vis[i][j] = 0;
        }

        dp = new int[row+1][col+1];
        for(int i = 0; i<=row; i++){
            for(int j = 0; j<=col; j++)
                dp[i][j] = -1;
        }

        solve(0, 0, row, col, grid, 0);
        return ans;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int row = sc.nextInt();
        int col = sc.nextInt();

        int grid[][] = new int[row][col];
        for(int i = 0; i<row; i++){
            for(int j = 0; j<col; j++)
                grid[i][j] = sc.nextInt();
        }

        System.out.print(minimumCostPath(grid));
        System.out.println();
        //System.out.print(dp[row-1][col-1]);
        for(int i = 0; i<row; i++){
            for(int j = 0; j<col; j++)
                System.out.print(dp[i][j]+" ");
            System.out.println();
        }
    }
}
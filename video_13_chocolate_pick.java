
import java.util.Arrays;


class video_13_chocolate_pick {
    public static int f(int i, int j1, int j2, int[][] grid,int[][][]dp){

//base case       
        int n = grid.length;
        int m = grid[0].length;
        if(j1<0 || j1>=m || j2<0 || j2>=m){
            return Integer.MIN_VALUE;
        }

// when you reach the last row

        if(i == n-1){
            if(j1 == j2){
                return grid[i][j1];
            }
            else{
                return grid[i][j1] + grid[i][j2] ;
            }
        }

// if already exixts return that value
        if(dp[i][j1][j2] != -1)
            return dp[i][j1][j2];


        int max = Integer.MIN_VALUE;

// we have to traverse for all 9 direction if I moves there are possibilities that II can move in all the three direction. 
        for(int dj1=-1 ; dj1<=1; dj1++){
            for(int dj2=-1; dj2<=+1; dj2++){
                int value=0;
                if(j1 == j2)
                    value = grid[i][j1];
                else
                    value = grid[i][j1] + grid[i][j2];

                value += f(i+1, j1+dj1 , j2+dj2, grid, dp);
                max = Math.max(max,value);
            }
        }
        return dp[i][j1][j2] = max;
    }

    public int solve(int n, int m, int grid[][]) {
        // Code here
        int [][][] dp = new int[n][m][m];
        for(int[][] d:dp)
            for(int [] dd:d)
                Arrays.fill(dd,-1);
        return f(0,0,m-1,grid,dp);
    }
}
//https://www.geeksforgeeks.org/problems/walls-coloring-ii--170647/1
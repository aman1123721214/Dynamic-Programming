import java.util.*;
class video_8_totalPathInGrid{
    public static int solve(int row, int col, int n, int m, int dp[][]){
        if(row == n-1 && col == m-1) return 1;
        if(row>=n || col>=m) return 0;
        if(dp[row][col]!=-1) return dp[row][col];

        int down = 0; int right = 0;
        down = solve(row+1, col, n, m, dp);
        right = solve(row, col+1, n, m, dp);

        return dp[row][col] = down+right;
    }

    //Function to find total number of unique paths.
    public static int NumberOfPath(int a, int b) {
        //Your code here
        int dp[][] = new int[a][b];
        for(int i = 0; i<a; i++){
            for(int j = 0; j<b; j++){
                dp[i][j] = -1;
            }
        }
        return solve(0, 0, a, b, dp);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        System.out.print(NumberOfPath(a, b));
    }
}
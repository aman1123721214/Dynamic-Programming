import java.util.*;
// import java.io.BufferedReader;
// import java.io.InputStreamReader;
// import java.io.IOException;
class video_25_LongestCommonSubsequence {
//method 1: memoization
    // public static int solve(int ind1, int ind2, String str1, String str2, int[][] dp){
    //     if(ind1<0 || ind2<0)    return 0;
    //     if(dp[ind1][ind2] != -1)    return dp[ind1][ind2];

    //     if(str1.charAt(ind1)==str2.charAt(ind2))
    //     return dp[ind1][ind2] = 1+solve(ind1-1, ind2-1, str1, str2, dp);

    //     else return dp[ind1][ind2] = Math.max(
    //         solve(ind1-1, ind2, str1, str2, dp), 
    //         solve(ind1, ind2-1, str1, str2, dp)
    //     );
    // }

    // // Function to find the length of longest common subsequence in two strings.
    // public static int lcs(int n, int m, String str1, String str2) {
    //     // your code here
    //     int dp[][] = new int[n][m];
    //     for(int row[]:dp)
    //         Arrays.fill(row, -1);
    //     return solve(n-1, m-1, str1, str2, dp);
    // }

//method 2: tabulation
    // public static int lcs(int n, int m, String str1, String str2) {
    //     // your code here
    //     int dp[][] = new int[n+2][m+2];
    //     for(int i = 0; i<=n; i++)   dp[i][0] = 0;
    //     for(int i = 0; i<=m; i++)   dp[0][i] = 0;

    //     for(int ind1 = 1; ind1<=n; ind1++){
    //         for(int ind2 = 1; ind2<=m; ind2++){
    //             if(str1.charAt(ind1-1)==str2.charAt(ind2-1))
    //             dp[ind1][ind2] = 1+dp[ind1-1][ind2-1];

    //             else dp[ind1][ind2] = Math.max(
    //                 dp[ind1-1][ind2], dp[ind1][ind2-1]
    //             );
    //         }
    //     }return dp[n][m];
    // }

//method 3: max space optimization
    public static int lcs(int n, int m, String str1, String str2) {
        // your code here
        int prev[] = new int[m+2];
        for(int i = 0; i<=m; i++)   prev[i] = 0;

        for(int ind1 = 1; ind1<=n; ind1++){
            int curr[] = new int[m+2];
            for(int ind2 = 1; ind2<=m; ind2++){
                if(str1.charAt(ind1-1)==str2.charAt(ind2-1))
                curr[ind2] = 1+prev[ind2-1];

                else curr[ind2] = Math.max(
                    prev[ind2], curr[ind2-1]
                );
            }
            prev = curr.clone();
        }return prev[m];
    }

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int m = sc.nextInt();
        String str1 = sc.next();
        String str2 = sc.next();

        System.out.print(lcs(n, m, str1, str2));
    }
}
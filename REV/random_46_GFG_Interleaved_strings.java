import java.util.*;
class Solution{
    static int n, m;
    private static boolean solve(int i, int j, String s1, String s2, String s3, int[][] dp){
        if(i == n && j == m) return true;

        if(dp[i][j] != -1) 
            return dp[i][j] == 1?true:false;

        boolean first = false, sec = false;
        int k = i+j;

        if(i<n && s1.charAt(i) == s3.charAt(k))
            first = solve(i+1, k, s1, s2, s3, dp);
        if(j<m && s2.charAt(j) == s3.charAt(k))
            sec = solve(i, j+1, s1, s2, s3, dp);
        
        boolean ans = first || sec;
        dp[i][j] = ans == true?1:0;
        return ans;
    }

    public boolean isInterleave(String s1, String s2, String s3){
        n = s1.length(); m = s2.length();
        int dp[][] = new int[n+1][m+1];
        for(int i = 0; i<=n; i++){
            for(int j = 0; j<=m; j++)
                dp[i][j] = -1;
        }

        return solve(0, 0, s1, s2, s3, dp);
    }
}

@SuppressWarnings("unused")
class random_46_GFG_Interleaved_strings{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s1 = sc.next();        
        String s2 = sc.next();        
        String s3 = sc.next();

        Solution solution = new Solution();
        System.out.println(solution.isInterleave(s1, s2, s3));        
    }
}
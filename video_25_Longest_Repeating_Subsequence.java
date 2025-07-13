// import java.util.*;

// class video_25_Longest_Repeating_Subsequence{
//     public static int solve(int ind1, int ind2, String str1, String str2, int[][] dp){
//         if(ind1<0 || ind2<0) return 0;
//         if(dp[ind1][ind2] != -1) return dp[ind1][ind2];

//         if(str1.charAt(ind1)==str2.charAt(ind2))
//         return dp[ind1][ind2] = 
//         1+solve(ind1-1, ind2-1, str1, str2, dp);

//         else return dp[ind1][ind2] = Math.max(
//             solve(ind1-1, ind2, str1, str2, dp), 
//             solve(ind1, ind2-1, str1, str2, dp)
//         );
//     }
//     public static int LongestRepeatingSubsequence(String str){
//         // code here
//         int n = str.length();
//         String str2 = "";
//         for(int i = str.length()-1; i>=0; i--)
//             str2 +=str.charAt(i);
//         int dp[][] = new int[n][n];
//         for(int row[]:dp)
//         Arrays.fill(row, -1);

//         return solve(n-1, n-1, str, str2, dp);
//     }

//     public static void main(String[] args) {
//         Scanner sc = new Scanner(System.in);
//         String str = sc.next();
//         System.out.print(LongestRepeatingSubsequence(str));
//     }
// }
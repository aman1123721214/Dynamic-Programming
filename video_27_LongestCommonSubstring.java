import java.util.*;
class video_27_LongestCommonSubstring {
//method 1: tabulation
    // public static int longestCommonSubstr(String s1, String s2) {
    //     // code here
    //     int n = s1.length();
    //     int m = s2.length();
    //     int maxi = (int)(-1e9);

    //     int dp[][] = new int[n+1][m+1];
    //     for(int i = 0; i<=n; i++)   dp[i][0] = 0;
    //     for(int i = 0; i<=m; i++)   dp[0][i] = 0;

    //     for(int i = 1; i<=n; i++){
    //         for(int j = 1; j<=m; j++){
    //             if(s1.charAt(i-1)==s2.charAt(j-1)){
    //                 dp[i][j] = 1+dp[i-1][j-1];
    //                 maxi = Math.max(maxi, dp[i][j]);
    //             }
    //             else dp[i][j] = 0;
    //         }
    //     }return maxi;
    // }

//method 2: space optimization
    public static int longestCommonSubstr(String s1, String s2) {
        // code here
        int n = s1.length();
        int m = s2.length();
        int maxi = (int)(-1e9);

        int prev[] = new int[m+1];
        for(int i = 0; i<=m; i++)   prev[i] = 0;

        for(int i = 1; i<=n; i++){
            int curr[] = new int[m+1];
            for(int j = 1; j<=m; j++){
                if(s1.charAt(i-1)==s2.charAt(j-1)){
                    curr[j] = 1+prev[j-1];
                    maxi = Math.max(maxi, curr[j]);
                }
                else curr[j] = 0;
            }
            prev = curr.clone();
        }
        if(maxi == -1e9) return 0;
        return maxi;
    }

    public static void main(String []args){
        Scanner sc = new Scanner(System.in);
        String s1 = sc.next();
        String s2 = sc.next();
        System.out.print(longestCommonSubstr(s1, s2));
    }
}
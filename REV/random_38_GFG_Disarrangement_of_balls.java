import java.util.*;
class Solution {
    static int mod = (int)(1e9+7);
    /************************** SPACE OPTIMIZATION ************************ */
    static int countDer(int n) {
        // Base case
        if(n == 0) return 1;
        if(n == 1) return 0;
        int prev2= 1; //dp[0]
        int prev1 = 0; //dp[1]
        for(int i = 2; i<=n; i++){
            int curr = ((i-1)*(prev2%mod + prev1%mod)%mod)%mod;
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
    /******************** TABULATION ************************* */
    // static int countDer(int n) {
    //     // Base case
    //     int dp[] = new int[n+1];
    //     // for(int i = 0; i<=n; i++) dp[i] = -1;

    //     dp[0] = 1; dp[1] = 0;
    //     for(int i = 2; i<=n; i++)
    //         dp[i] = ((i-1)*(dp[i-1]%mod + dp[i-2]%mod)%mod)%mod;
        
    //     return dp[n];
    // }

    /************************* MEMOIZATION *************************/
    // private static int solve(int n,  int dp[]){
    //     if(n == 0) return 1;
    //     if(n == 1) return 0;

    //     if(dp[n] != -1) return dp[n];
    //     return dp[n] = ((n-1)*(solve(n-1, dp)%mod + solve(n-2, dp)%mod)%mod)%mod;
    // }
    // static int countDer(int n) {
    //     // Base case
    //     int dp[] = new int[n+1];
    //     for(int i = 0; i<=n; i++) dp[i] = -1;

    //     return solve(n, dp);
    // }
}

@SuppressWarnings("unused")
class random_38_GFG_Disarrangement_of_balls{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        System.out.println(new Solution().countDer(n));
    }
}
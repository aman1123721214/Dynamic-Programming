import java.util.*;

class Solution {
    private static boolean  solve(int ind, int sum, int arr[], boolean  dp[][]){
        if(sum != 0 && (sum == 2024 || (sum%20 == 0) || (sum%24 == 0))) return true; 
        if(ind<0 || sum>2024) return false;

        if(dp[ind][sum]) return dp[ind][sum] ;

        boolean take = solve(ind-1, sum+arr[ind], arr, dp);
        boolean nTake = solve(ind-1, sum, arr, dp);

        return dp[ind][sum] = take || nTake;    
    }
    public static boolean isPossible(int N, int[] coins) {
        // code here
        boolean dp[][] = new boolean[N][2024];
        for(boolean row[]:dp)
            Arrays.fill(row, false);
        
        return solve(N-1, 0, coins, dp);
    }
}

@SuppressWarnings("unused")
class random_87_GFG_New_Year_Resolution{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();

        int arr[] = new int[N];
        for(int i = 0; i<N; i++)
            arr[i] = sc.nextInt();
        
        Solution obj = new Solution();
        System.out.println(obj.isPossible(N, arr));
    }
}
import java.util.*;
class video_14_subsetSum {
//method 1: memoization
    // public static boolean solve(int ind, int target, int arr[], int dp[][]){
    //     if(target==0)  return true;
        
    //     if(ind<0 || target<0) return false;

    //     if(dp[ind][target]!=-1){
    //         if(dp[ind][target]==0) return false;
    //         return true;
    //     }

    //     boolean take = solve(ind-1, target-arr[ind], arr ,dp);
    //     boolean nTake = solve(ind-1, target, arr, dp);

    //     boolean ans = take || nTake;
    //     if(ans == false) dp[ind][target] = 0;
    //     else dp[ind][target] = 1;
    //     return ans; 
    // }

    // public static boolean isSubsetSum(int arr[], int sum) {
    //     // code here
    //     int n = arr.length;
    //     int dp[][] = new int[n][sum+1];
    //     for(int row[]:dp)
    //         Arrays.fill(row, -1);
    //     return solve(n-1, sum, arr, dp);
    // }
    public static boolean isSubsetSum(int arr[], int sum) {
        // code here
        int n = arr.length;
        boolean dp[][] = new boolean[n][sum+1];
        for(int i = 0; i<n; i++)
            dp[i][0] = true;
        dp[0][arr[0]] = true;

        for(int ind = 1; ind<n; ind++){
            for(int target = 1; target<sum+1; target++){
                boolean take = dp[ind-1][target-arr[ind]];
                boolean nTake = dp[ind-1][target];

                dp[ind][target] = take || nTake;
            }
        }
        return dp[n-1][sum];
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner (System.in);
        int n = sc.nextInt();

        int arr[] = new int[n];
        for(int i = 0; i<n; i++)
            arr[i] = sc.nextInt();
        int target = sc.nextInt();

        System.out.print(isSubsetSum(arr, target));
    }
}
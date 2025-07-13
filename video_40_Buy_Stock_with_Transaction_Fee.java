import java.util.*;

class video_40_Buy_Stock_with_Transaction_Fee {
//method 1: memoization
    // public static long solve(int ind, int buy, int arr[], long dp[][], int k){
    //     if(ind == arr.length)   return 0;
    //     if(dp[ind][buy] != -1)  return dp[ind][buy];

    //     long profit = 0;
    //     if(buy == 1){
    //         profit = Math.max(-arr[ind]+solve(ind+1, 0, arr, dp, k),
    //         solve(ind+1, 1, arr, dp, k));
    //     }
    //     else{
    //         profit = Math.max(-k+arr[ind]+solve(ind+1, 1, arr, dp, k),
    //         solve(ind+1, 0, arr, dp, k));
    //     }
    //     return dp[ind][buy] = profit;
    // }
    // public static long maximumProfit(int arr[], int k) {
    //     // Code here
    //     int n = arr.length;
    //     long dp[][] = new long[n][2];
    //     for(int i = 0; i<n; i++) 
    //     dp[i][0] = dp[i][1] = -1;
    //     return solve(0, 1, arr, dp, k);
    // }

//method 2: tabulation
    // public static long maximumProfit(int arr[], int k) {
    //     // Code here
    //     int n = arr.length;
    //     long dp[][] = new long[n+1][2];
    //     dp[n][0] = dp[n][1] = 0;

    //     for(int ind = n-1; ind>=0; ind--){
    //         for(int buy = 0; buy<=1; buy++){
    //             long profit = 0;
    //             if(buy == 1){
    //                 profit = Math.max(-arr[ind]+dp[ind+1][0],
    //                 dp[ind+1][1]);
    //             }
    //             else{
    //                 profit = Math.max(-k+arr[ind]+dp[ind+1][1],
    //                 dp[ind+1][0]);
    //             }
    //             dp[ind][buy] = profit;
    //         }
    //     }
    //     return dp[0][1];
    // }
//method 3: max space optimization
    public static long maximumProfit(int arr[], int k) {
        // Code here
        int n = arr.length;
        long prev[] = new long[2];
        prev[0] = prev[1] = 0;

        for(int ind = n-1; ind>=0; ind--){
            long curr[] = new long[2];
            for(int buy = 0; buy<=1; buy++){
                long profit = 0;
                if(buy == 1){
                    profit = Math.max(-arr[ind]+prev[0],
                    prev[1]);
                }
                else{
                    profit = Math.max(-k+arr[ind]+prev[1],
                    prev[0]);
                }
                curr[buy] = profit;
            }prev = curr.clone();
        }
        return prev[1];
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int arr[] = new int[n];
        int k = sc.nextInt();
        for(int i = 0; i<n; i++)arr[i] = sc.nextInt();

        System.out.print(maximumProfit(arr, k));
    }
}
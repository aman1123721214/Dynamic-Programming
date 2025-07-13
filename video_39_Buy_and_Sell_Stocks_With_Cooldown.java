import java.util.*;
class video_39_Buy_and_Sell_Stocks_With_Cooldown{
//method 1: memoization
    // public static long solve(int ind, int buy, long price[], long dp[][]){
    //     if(ind>=price.length)   return 0;
    //     if(dp[ind][buy] != -1) return dp[ind][buy];

    //     long profit = 0;
    //     if(buy == 1){
    //         profit = Math.max(-price[ind]+solve(ind+1, 0, price, dp),
    //         solve(ind+1, 1, price, dp));
    //     }
    //     else{
    //         profit = Math.max(price[ind]+solve(ind+2, 1, price, dp),
    //         solve(ind+1, 0, price, dp));
    //     }
    //     return dp[ind][buy] = profit;
    // }
    // public static long maximumProfit(long prices[], int n){
    //     //Code here
    //     long dp[][] = new long[n][2];
    //     for(int i = 0; i<n; i++)
    //         dp[i][0] = dp[i][1] = -1;
    //     return solve(0, 1, prices, dp);
    // }

//method 2: tabulation
    public static long maximumProfit(long price[], int n){
        //Code here
        long dp[][] = new long[n+2][2];
        dp[n][0] = dp[n][1] = dp[n+1][0] = dp[n+1][1] = 0;

        for(int ind = n-1; ind>=0; ind--){
            for(int buy = 0; buy<=1; buy++){
                long profit = 0;
                if(buy == 1){
                    profit = Math.max(-price[ind]+dp[ind+1] [0],
                    dp[ind+1][1]);
                }
                else{
                    profit = Math.max(price[ind]+dp[ind+2][1],
                    dp[ind+1][0]);
                }
                dp[ind][buy] = profit;
            }
        }
        return dp[0][1];
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long arr[] = new long[n];
        for(int i = 0; i<n; i++)
            arr[i] = sc.nextInt();
        
        System.out.print(maximumProfit(arr, n));
    }
}
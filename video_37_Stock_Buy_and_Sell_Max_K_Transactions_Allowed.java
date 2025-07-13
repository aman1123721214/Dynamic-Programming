import java.util.*;
class video_37_Stock_Buy_and_Sell_Max_K_Transactions_Allowed {
//method 1: memoization
    // public static int solve(int ind, int cap, int buy, int price[], int dp[][][]){
    //     if(ind == price.length || cap == 0) return 0;
    //     if(dp[ind][cap][buy] != -1) return dp[ind][cap][buy];

    //     int profit = 0;
    //     if(buy == 1){
    //         profit = Math.max(-price[ind]+solve(ind+1, cap, 0, price, dp),
    //         solve(ind+1, cap, 1, price, dp));
    //     }
    //     else {
    //         profit = Math.max(price[ind]+solve(ind+1, cap-1, 1, price, dp),
    //         solve(ind+1, cap, 0, price, dp));
    //     }

    //     return dp[ind][cap][buy] = profit;
    // }
    // public static int maxProfit(int k, int n, int price[]) {
    //     // code here
    //     int dp[][][] = new int [n][k+1][2];
    //     for(int i = 0; i<n; i++){
    //         for(int j = 0; j<=k; j++)
    //         dp[i][j][0] = dp[i][j][1] = -1;
    //     }

    //     return solve(0, k, 1, price, dp);
    // }

//method 2: tabulation
    // public static int maxProfit(int k, int n, int price[]) {
    //     // code here
    //     int dp[][][] = new int [n+1][k+1][2];
    //     dp[n][0][0] = dp[n][0][1] = 0;

    //     for(int ind = n-1; ind>=0; ind--){
    //         for(int cap = 1; cap<=k; cap++){
    //             for(int buy = 0; buy<=1; buy++){
    //                 int profit = 0;
    //                 if(buy == 1){
    //                     profit = Math.max(-price[ind]+dp[ind+1][cap][0],
    //                     dp[ind+1][cap][1]);
    //                 }
    //                 else {
    //                     profit = Math.max(price[ind]+dp[ind+1][cap-1][1],
    //                     dp[ind+1][cap][0]);
    //                 }
    //                 dp[ind][cap][buy] = profit;
    //             }
    //         }
    //     }
    //     return dp[0][k][1];
    // }

//method 3: max space optimization
    public static int maxProfit(int k, int n, int price[]) {
        // code here
        int prev[][] = new int[k+1][2];
        prev[0][0] = prev[0][1] = 0;

        for(int ind = n-1; ind>=0; ind--){
            int curr[][] = new int[k+1][2];
            for(int cap = 1; cap<=k; cap++){
                for(int buy = 0; buy<=1; buy++){
                    int profit = 0;
                    if(buy == 1){
                        profit = Math.max(-price[ind]+prev[cap][0],
                        prev[cap][1]);
                    }
                    else {
                        profit = Math.max(price[ind]+prev[cap-1][1],
                        prev[cap][0]);
                    }
                    curr[cap][buy] = profit;
                }
            }
            prev = curr.clone();
        }
        return prev[k][1];
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int k = sc.nextInt();
        int n = sc.nextInt();

        int arr[] = new int[n];
        for(int i = 0; i<n; i++)
        arr[i] = sc.nextInt();

        System.out.print(maxProfit(k, n, arr));
    }

}
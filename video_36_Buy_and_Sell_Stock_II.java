import java.util.*;
class video_36_Buy_and_Sell_Stock_II {
    public static int solve(int ind, int buy, int []prices, int dp[][]){
        if(ind==prices.length)
            return 0;
        if(dp[ind][buy] != -1) return dp[ind][buy];

        int profit = 0;
        if(buy == 1)
        profit = Math.max(-prices[ind]+solve(ind+1, 0, prices, dp),
        solve(ind+1, 1, prices, dp));

        else profit = Math.max(prices[ind]+solve(ind+1, 1, prices, dp), 
        solve(ind+1, 0, prices, dp));

        return dp[ind][buy] = profit;

    }
    public static int maximumProfit(int prices[]) {
        // code here
        int n = prices.length;
        int dp[][] = new int[n][2];
        for(int i = 0; i<n; i++){
            dp[i][0] = dp[i][1] = -1;
        }
        return solve(0, 1, prices, dp);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n =  sc.nextInt();
        int prices[] = new int[n];
        for(int i = 0; i<n; i++) prices[i] = sc.nextInt();

        System.out.print(maximumProfit(prices));
    }
}
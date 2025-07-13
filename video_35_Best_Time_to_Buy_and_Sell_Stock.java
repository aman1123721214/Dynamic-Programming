import java.util.*;
class video_35_Best_Time_to_Buy_and_Sell_Stock {
    // public static int maximumProfit(int prices[]) {
    //     // Code here
    //     int maxi = (int)(-1e9);
    //     for(int i = 1; i<prices.length; i++){
    //         for(int j = 0; j<i; j++){
    //             int buy = prices[i];
    //             int sell = prices[j];
    //             int profit = buy-sell;
    //             maxi = Math.max(maxi, profit);
    //         }
    //     }
    //     if(maxi<=0 || prices.length == 1) return 0;
    //     return maxi;
    // }
    public static int maximumProfit(int prices[]) {
        // Code here
        int maxi = 0;
        int mini = prices[0];
        for(int i = 1; i<prices.length; i++){
            int profit = prices[i]-mini;
            maxi = Math.max(maxi, profit);
            mini = Math.min(mini, prices[i]);
        }return maxi;
    }

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int prices[] = new int[n];
        for(int i = 0; i<n; i++)    
            prices[i] = sc.nextInt();
        System.out.print(maximumProfit(prices));
    }
}
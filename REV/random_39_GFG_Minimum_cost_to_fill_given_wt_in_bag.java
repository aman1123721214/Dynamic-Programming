import java.util.*;
class Solution {
  private static int solve(int ind, int wt, int cost[], int dp[][]){
    if(wt == 0) return 0;
    if(ind>wt) return (int)(1e9);

    if(dp[ind][wt] != -1) return dp[ind][wt];

    int buy = (int)(1e9);
    int nBuy = (int)(1e9);

    if(wt-ind>=0 && cost[ind-1] != -1){ 
            buy = solve(ind, wt-ind, cost, dp);
            if(buy != (int)(1e9)) buy+=cost[ind-1];
    }
    
    nBuy = solve(ind+1, wt, cost, dp);
    return Math.min(buy, nBuy);
  }
  public static int minimumCost(int n, int wt, int cost[]){
    //Code Here
    int dp[][] = new int[n+1][wt+1];
    for(int i = 0; i<=n; i++){
        for(int j = 0; j<=wt; j++)
            dp[i][j] = -1;
    }
    
    return solve(1, wt, cost, dp);
  }
}

class random_39_GFG_Minimum_cost_to_fill_given_wt_in_bag{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int w = sc.nextInt();

        int cost[] = new int[n];

        System.out.println(Solution.minimumCost(n, w, cost));
    }
}
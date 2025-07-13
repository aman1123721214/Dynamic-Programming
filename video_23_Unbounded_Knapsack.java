// import java.util.*;
// class video_23_Unbounded_Knapsack{
//method 1: memoization
    // public static int solve(int ind, int capacity, int val[], int wt[], int dp[][]){
    //     if(capacity==0) return dp[ind][capacity] = 0;
    //     if(ind==0)  return (capacity/wt[0])*val[0];
    //     if(ind<0 || capacity<0)   return (int)(-1e9);

    //     if(dp[ind][capacity] != -1) return dp[ind][capacity];

    //     int nTake = solve(ind-1, capacity, val, wt, dp);
    //     int take = val[ind] + solve(ind, capacity-wt[ind], val, wt, dp);
    //     return dp[ind][capacity] = Math.max(take, nTake);
    // }

    // public static int knapSack(int N, int W, int val[], int wt[]){
    //     // code here
    //     int dp[][] = new int[N][W+1];
    //     for(int row[]:dp)
    //         Arrays.fill(row, -1);
    //     int ans = solve(N-1, W, val, wt, dp);
    //     if(ans != -1e9) return ans;
    //     return 0;
    // }

//method 2: tabulation
    // public static int knapSack(int N, int W, int val[], int wt[]){
    //     // code here
    //     int dp[][] = new int[N][W+1];
    //     for(int w = 0; w<=W; w++){
    //         dp[0][w] = ((int)w/wt[0])*val[0];
    //     }

    //     for(int ind = 1; ind<N; ind++){
    //         for(int w = 0; w<=W; w++){
    //             int nTake = dp[ind-1][w];
    //             int take = (int)(-1e9);
    //             if(wt[ind]<=w)
    //                 take = val[ind]+dp[ind][w-wt[ind]];

    //             dp[ind][w] = Math.max(take, nTake);
    //         }
    //     }
    //     return dp[N-1][W];
    // }

//method 3: space optimization
    // public static int knapSack(int N, int W, int val[], int wt[]){
    //     // code here
    //     int prev[] = new int[W+1];
    //     for(int w = 0; w<=W; w++){
    //         prev[w] = ((int)w/wt[0])*val[0];
    //     }

    //     for(int ind = 1; ind<N; ind++){
    //         int curr[] = new int[W+1];
    //         for(int w = 0; w<=W; w++){
    //             int nTake = prev[w];
    //             int take = (int)(-1e9);
    //             if(wt[ind]<=w)
    //                 take = val[ind]+curr[w-wt[ind]];

    //             curr[w] = Math.max(take, nTake);
    //         }prev = curr.clone();
    //     }
    //     return prev[W];
    // }

    // public static void main(String[] args){
    //     Scanner sc = new Scanner (System.in);
    //     int n, w;
    //     n = sc.nextInt();
    //     w = sc.nextInt();

    //     int val[] = new int[n];
    //     int wt[] = new int[n];

    //     for(int i = 0; i<n; i++)    val[i] = sc.nextInt();
    //     for(int i = 0; i<n; i++)    val[i] = sc.nextInt();

    //     System.out.print(knapSack(n, w, val, wt));
    // }
//}
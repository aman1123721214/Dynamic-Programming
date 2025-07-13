// import java.util.*;

// class video_19_01Knapsack {
//method 1: memoization
    // public static int solve(int ind, int W, int val[], int wt[], int dp[][]){

    //     if(ind==0){
    //         if(wt[0]<=W)    return val[0];
    //         return 0;
    //     }
    //     if(dp[ind][W]!=-1)  return dp[ind][W];

    //     int nTake = solve(ind-1, W, val, wt, dp);
    //     int take = (int)(-1e9);
    //     if(wt[ind]<=W)
    //         take = val[ind] + solve(ind-1, W-wt[ind], val, wt, dp);
        
    //     return dp[ind][W] = Math.max(nTake, take);
    // }
    // // Function to return max value that can be put in knapsack of capacity.
    // static int knapSack(int capacity, int val[], int wt[]) {
    //     // code here
    //     int n = val.length;
    //     int dp[][] = new int[n][capacity+1];
    //     for(int row[]:dp)
    //     Arrays.fill(row, -1);
    //     return solve(n-1, capacity, val, wt, dp);
    // }

//method 2: tabulation
    // static int knapSack(int capacity, int val[], int wt[]) {
    //     // code here
    //     int n = val.length;
    //     int dp[][] = new int[n][capacity+1];
        
    //     for(int w = wt[0]; w<=capacity; w++)
    //         dp[0][w] = val[0];
    //     for(int i = 0; i<n; i++)
    //         dp[i][0] = 0;

    //     for(int ind = 1; ind<n; ind++){
    //         for(int w = 1; w<=capacity; w++){
    //             int nTake = dp[ind-1][w];
    //             int take = (int)(-1e9);
    //             if(wt[ind]<=w)
    //                 take = val[ind]+dp[ind-1][w-wt[ind]];
                
    //             dp[ind][w] = Math.max(take, nTake);
    //         }
    //     }
    //     return dp[n-1][capacity];
    // }

//method 3: max space optimisation
    // static int knapSack(int capacity, int val[], int wt[]) {
    //     // code here
    //     int n = val.length;
    //     int prev[] = new int[capacity+1];

    //     for(int w = wt[0]; w<=capacity; w++)
    //         prev[w] = val[0];

    //     for(int ind = 1; ind<n; ind++){
    //         int curr[] = new int[capacity+1];
    //         for(int w = 1; w<=capacity; w++){
    //             int nTake = prev[w];
    //             int take = (int)(-1e9);
    //             if(wt[ind]<=w)
    //                 take = val[ind]+prev[w-wt[ind]];
                
    //             curr[w] = Math.max(take, nTake);
    //         }prev = curr.clone();
    //     }
    //     return prev[capacity];
    // }

//     public static void main(String[] args) {
//         Scanner sc = new Scanner(System.in);
//         int n = sc.nextInt();

//         int val[] = new int[n];
//         int wt[] = new int[n];

//         for(int i = 0; i<n; i++)    val[i] = sc.nextInt();
//         for(int i = 0; i<n; i++)    wt[i] = sc.nextInt();
//         int capacity = sc.nextInt();
//         System.out.print(knapSack(capacity, val, wt));
//     }
// }
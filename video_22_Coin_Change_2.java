// import java.util.*;
// class video_22_Coin_Change_2 {
//method 1: memoization
    // public static long solve(int ind, int target, int coins[], long dp[][]){
    //     if(target==0)   return 1;
    //     if(target<0 || ind<0)   return 0;

    //     if(dp[ind][target] != -1)   return dp[ind][target];
    //     long nTake = solve(ind-1, target, coins, dp);
    //     long take = solve(ind, target-coins[ind], coins, dp);

    //     return dp[ind][target] = (take+nTake);
    // }
    // public static long count(int coins[], int sum) {
    //     // code here.
    //     int n = coins.length;
    //     long dp[][] = new long[n][sum+1];
    //     for(long row[]:dp)
    //         Arrays.fill(row, -1);
    //     return solve(n-1, sum, coins, dp);
    // }
//method 2: tabulation
//      public static long count(int coins[], int sum) {
//         // code here.
//         int n = coins.length;
//         long prev[] = new long[sum+1];
        
//         for(int s = 0; s<=sum; s++)
//             if(s%coins[0]==0)   prev[s] = 1;

//         for(int ind = 1; ind<n; ind++){
//             long curr[] = new long[sum+1];
//             for(int s = 0; s<=sum; s++){
//                 long nTake = prev[s];
//                 long take = 0;
//                 if(coins[ind]<=s)
//                     take =  curr[s-coins[ind]];
                
//                 curr[s] = (take+nTake);
//             }prev = curr.clone();
//         }
//         return prev[sum];
//     }

//     public static void main(String[] args) {
//         Scanner sc = new Scanner(System.in);
//         int n = sc.nextInt();
//         int coins[] = new int[n];
//         for(int i = 0; i<n; i++)    
//             coins[i] = sc.nextInt();
//         int sum = sc.nextInt();

//         System.out.print(count(coins, sum));
//     }
// }
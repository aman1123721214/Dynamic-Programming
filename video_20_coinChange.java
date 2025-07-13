import java.util.*;
class video_20_coinChange {
//method 1: memoization
    // public static int solve(int ind, int amnt, int nums[], int dp[][]){
    //     //base case
    //     if(amnt==0)   return 0;
    //     if(ind<0)   return (int)(1e9);
    //     if(dp[ind][amnt]!=-1)   return dp[ind][amnt];

    //     int nTake = solve(ind-1, amnt, nums, dp);
    //     int take = (int)(1e9);
    //     if(nums[ind]<=amnt)
    //     take = 1 + solve(ind, amnt-nums[ind], nums, dp);

    //     return dp[ind][amnt] = Math.min(take, nTake);
    // }
    // public static int MinCoin(int[] nums, int amount) {
    //     // Code here
    //     int n = nums.length;
    //     int dp[][] = new int[n][amount+1];
    //     for(int i = 0; i<n; i++)
    //         for(int j = 0; j<=amount; j++)
    //             dp[i][j] = -1;
        
    //     int ans = (int)(1e9);
    //     ans = solve(n-1, amount, nums, dp);
    //     if(ans!=1e9)
    //         return ans;
    //     return -1;
    // }

//method 2: tabulation
    // public static int MinCoin(int[] nums, int amount) {
    //     // Code here
    //     int n = nums.length;
    //     int dp[][] = new int[n][amount+1];

    //     for(int val = 0; val<=amount; val++)
    //         if(val%nums[0]==0)  dp[0][val] = val/nums[0];
    //         else dp[0][val] = (int)(1e9);


    //     for(int ind = 1; ind<n; ind++){
    //         for(int val = 0; val<=amount; val++){
    //             int nTake = dp[ind-1][val];
    //             int take = (int)(1e9);
    //             if(nums[ind]<=val)
    //                 take = 1+dp[ind][val-nums[ind]];
                
    //             dp[ind][val] = Math.min(take, nTake);
    //         }
    //     }
    //     if(dp[n-1][amount]!=1e9)    return dp[n-1][amount];
    //     return -1;
    // }
//method 3: max space optimization
    public static int MinCoin(int[] nums, int amount) {
        // Code here
        int n = nums.length;
        int prev[] = new int[amount+1];

        for(int val = 0; val<=amount; val++)
            if(val%nums[0]==0)  prev[val] = val/nums[0];
            else prev[val] = (int)(1e9);


        for(int ind = 1; ind<n; ind++){
            int curr[] = new int[amount+1];
            for(int val = 0; val<=amount; val++){
                int nTake = prev[val];
                int take = (int)(1e9);
                if(nums[ind]<=val)
                    take = 1+curr[val-nums[ind]];
                
                curr[val] = Math.min(take, nTake);
            }
            prev = curr.clone();
        }
        if(prev[amount]!=1e9)    return prev[amount];
        return -1;
    }

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int nums[] = new int[n];
        for(int i = 0; i<n; i++)    nums[i] = sc.nextInt();
        int amount = sc.nextInt();
        System.out.print(MinCoin(nums, amount));    
    }
}

import java.util.Arrays;

class video_15_partitionEqualSubset {
    public static boolean solve(int ind, int target, int arr[], int dp[][]){
        if(ind<0 || target<0) return false;
        if(target==0) return true;
        if(dp[ind][target]!=-1){
            if(dp[ind][target]==0)  return false;
            return true;
        }

        boolean take = solve(ind-1, target-arr[ind], arr, dp);
        boolean nTake = solve(ind-1, target, arr, dp);
        boolean ans = take||nTake;

        if(ans==true)dp[ind][target] = 1;
        else dp[ind][target] = 0;

        return ans;
    }

    static boolean equalPartition(int arr[]) {
        // code here
        int n = arr.length;
        if(n==1)return false;

        int sum = 0;
        for(int i = 0; i<n; i++)
            sum+=arr[i];
        
        if(sum%2 != 0) return false;

        int dp[][] = new int[n][(sum/2)+1];
        for(int row[]:dp)
            Arrays.fill(row, -1);
        return solve(n-1, sum/2, arr, dp);
    }
}
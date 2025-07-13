import java.util.*;
class video_21_TargetSum {
    public static int countPartitions(int n, int d, int[] arr) {
        // code here
        int sum = 0;
        for(int i = 0; i<n; i++)    sum+=arr[i];
        int target = (sum-d)/2;
        if((sum-d)<0 || (sum-d)%2==1) return 0;

        int dp[][] = new int[n][target+1];
        for(int j=0;j<=target;j++){
            if(arr[0]==0)   dp[0][arr[0]]=2;
            else if(arr[0]==j)  dp[0][j]=1;
        }

        if(arr[0] != 0 && arr[0]<=target) dp[0][arr[0]] = 1;
        for(int ind = 1; ind<n; ind++){
            for(int s = 0; s<=target; s++){
                int nTake = dp[ind-1][s];
                int take = 0;
                if(arr[ind]<=s)
                    take = dp[ind-1][s-arr[ind]];
                
                dp[ind][s] = (take+nTake);
            }
        }
        return dp[n-1][target];
    }
    public static int findTargetSumWays( int N, int[] A ,int target) {
        // code here
        return countPartitions(N, target, A);
    }
};
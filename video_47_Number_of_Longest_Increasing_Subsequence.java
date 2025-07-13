import java.util.*;
class video_47_Number_of_Longest_Increasing_Subsequence{
    public int NumberofLIS(int N, int arr[]){
        // Code here
        int dp[] = new int[N], count[] = new int[N];
        Arrays.fill(dp, 1);
        Arrays.fill(count, 1);
        int maxLen = 1;
        for(int i = 0; i<N; i++){
            for(int j = 0; j<i; j++){
                if(arr[i]>arr[j] && 1+dp[j]>dp[i]){
                    dp[i] = 1+dp[j];
                    count[i] = count[j];
                }
                else if(arr[i]>arr[j] && dp[i] == 1+dp[j])
                    count[i]+=count[j];
                maxLen = Math.max(maxLen, dp[i]);
            }
        }

        int ans = 0;
        for(int i = 0; i<N; i++)
        if(dp[i] == maxLen) ans+=count[i]; 
        return ans;
    }
}
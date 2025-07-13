import java.util.*;

class video_16_partitionMinSubsetDiff{

	public static int minDifference(int arr[], int n) { 
	    // Your code goes here
        int sum = 0;
        for(int i:arr)
            sum+=i;
        //sum /=2;

        boolean dp[][] = new boolean [n][sum+1];

        for(int i = 0; i<n; i++)
            dp[i][0] = true;
        if(arr[0]<=sum) dp[0][arr[0]] = true;

        for(int i = 1; i<n; i++){
            for(int s1 = 1; s1<=(sum+1)/2; s1++){
                boolean nTake = dp[i-1][s1];
                boolean take = false;
                if(arr[i]<=s1)
                take = dp[i-1][s1-arr[i]];

                dp[i][s1] = take||nTake;
            }
        }
        int ans = (int)(1e9);
        for(int s1 = 0; s1<=sum/2; s1++)
            if(dp[n-1][s1]==true)
                ans = Math.min(ans, Math.abs((sum-s1)-s1));
        return ans;
	} 

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int arr[] = new int[n];
        for(int i = 0; i<n; i++)
            arr[i] = sc.nextInt();
        
        System.out.print(minDifference(arr, n));
    }
}
import java.util.*;
class video_17_countSubsetsHavingSum_k{
   
    public static int solve(int ind, int target, int arr[], int dp[][]){
        if(ind<0){
            if(target==0)   return 1;
            return 0;
        }
        if(dp[ind][target]!=-1) return dp[ind][target];

        int nTake = solve(ind-1, target, arr, dp);    //
        int take = 0;
        if(arr[ind]<=target) 
        take = solve(ind-1, target-arr[ind], arr, dp);    //

        return dp[ind][target] = (take+nTake)%1000000007;
    }

	public static int perfectSum(int arr[],int n, int sum) { 
	    // Your code goes here
		int dp[][] = new int[n][sum+1];
        for(int row[]:dp)   Arrays.fill(row, -1);
        return solve(n-1, sum, arr, dp);
	} 

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int arr[] = new int[n];
        for(int i = 0; i<n; i++)
            arr[i] = sc.nextInt();
        int sum = sc.nextInt();

        System.out.print(perfectSum(arr, n, sum));
    }
}
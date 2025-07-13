import java.io.*;
class Solution {
  private static int solve(int i, int j, int arr[], int dp[][]){
        if(i>j) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        int maxi = Integer.MIN_VALUE;
        for(int ind = i; ind<=j; ind++){
            int cost = arr[i-1]*arr[ind]*arr[j+1]+
             solve(i,ind-1, arr, dp)+solve(ind+1, j, arr, dp);

            maxi = Math.max(maxi, cost);
        }     
        return dp[i][j] = maxi; 
    }
  public static int maxCoins(int[] arr) {
        // code here
        int n = arr.length;
        
        int dp[][] = new int[n+1][n+1];
        for(int i = 0; i<=n; i++){
            for(int j = 0; j<=n; j++)
                dp[i][j] = -1;
        }

        int temp[] = new int[n+2];
        temp[0] = 1;
        temp[n+1] = 1;
        for(int i = 1; i<=n; i++) temp[i] = arr[i-1];

        return solve(1, n, temp, dp);
    }
}

@SuppressWarnings("unused")
class random_25_GFG_Burst_Balloons{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str[] = br.readLine().trim().split(" ");

        int arr[] = new int[str.length];
        for(int i = 0; i<str.length; i++)
            arr[i] = Integer.parseInt(str[i]);
        
        Solution obj = new Solution();
        System.out.print(obj.maxCoins(arr));
    }
}
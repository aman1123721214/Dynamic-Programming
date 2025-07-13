import java.util.*;
class video_41_Longest_Increasing_Subsequence {
//method 1: memoization
    // public static int solve(int ind, int prevInd, int arr[], int [][]dp){
    //     if(ind == arr.length)   return 0;
    //     if(dp[ind][prevInd+1] != -1)
    //         return dp[ind][prevInd+1];

    //     int len = solve(ind+1, prevInd, arr, dp);
    //     if(prevInd == -1 || arr[ind]>arr[prevInd])
    //     len = Math.max(len, 1+solve(ind+1, ind, arr, dp));

    //     return dp[ind][prevInd+1] = len;
    // }
    
    // // Function to find length of longest increasing subsequence.
    // public static int longestSubsequence(int arr[]) {
    //     // code here
    //     int n = arr.length;
    //     int dp[][] = new int[n][n+1];
    //     for(int i = 0; i<n; i++)
    //         for(int j = 0; j<=n; j++)
    //             dp[i][j] = -1;
    //     return solve(0, -1, arr, dp);
    // }
//method 2: tabulation
    public static int longestSubsequence(int arr[]) {
        // code here
        int n = arr.length;
        int dp[][] = new int[n+1][n+1];
        for(int i = 0; i<=n; i++)
            dp[n][i] = 0;
        for(int ind = n-1; ind>=0; ind--){
            for(int prevInd = ind-1; prevInd>=-1; prevInd--){
                int len = dp[ind+1][prevInd+1];
                
                if(prevInd == -1 || arr[ind]>arr[prevInd])
                len = Math.max(len, 1+dp[ind+1][ind+1]);

                dp[ind][prevInd+1] = len;
            }
        }

        for(int i = 0; i<=n; i++){
            for(int j = 0; j<=n; j++)
            System.out.print(dp[i][j]+" ");
            System.out.println();
        }
        return dp[0][0];
    }
    // public static int longestSubsequence(int arr[]) {
    //     // code here
    //     int n = arr.length;
    //     ArrayList<Integer> temp = new ArrayList<>();
    //     temp.add(arr[0]);

    //     int len = 1;
    //     for(int i = 1; i<n; i++){
    //         if(arr[i]>temp.get(temp.size()-1)){
    //             temp.add(arr[i]);
    //             len++;
    //         }
    //         else{
    //             int ind = Collections.binarySearch(temp, arr[i]);
    //             if(ind<0)   ind = -ind-1;
    //             temp.set(ind, arr[i]);
    //         }
    //     }
    //     return len;
    // }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int arr[] = {5, 8, 3, 7, 9, 1};
        System.out.print(longestSubsequence(arr));
    }
}
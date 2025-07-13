import java.util.*;
class video_42_Printing_Longest_Increasing_Subsequence {
    public static ArrayList<Integer> longestIncreasingSubsequence(int n, int arr[]) {
        // Code here
        int dp[] = new int[n];
        Arrays.fill(dp, 1);
        int maxi = 1;
        for(int ind = 0; ind<n-1; ind++){
            for(int prevInd = 0; prevInd<ind; prevInd++){
                if(arr[ind]>arr[prevInd]){
                    dp[ind] = Math.max(1+dp[prevInd], dp[ind]);
                }
            }
            maxi = Math.max(maxi, dp[ind]);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int arr[] = new int[n];

        for(int i = 0; i<n; i++)
            arr[i] = sc.nextInt();
        ArrayList<Integer> ans = longestIncreasingSubsequence(n, arr);
        for(int it: ans)
            System.out.print(it+" ");
    }
}
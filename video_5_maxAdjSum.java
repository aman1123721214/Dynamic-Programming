import java.util.*;
class video_5_maxAdjSum {
//method 1: memoization-->

    // public static int solve(int ind, int arr[], int dp[], int n){
    //     if(ind>=n) return 0;

    //     if(dp[ind] != -1) return dp[ind];

    //     int Pick = arr[ind]+solve(ind+2, arr, dp, n);
    //     int nPick = solve(ind+1, arr, dp, n);

    //     return dp[ind] = Math.max(Pick, nPick); 

    // }
    
    // int findMaxSum(int arr[], int n) {
    //     // code here
    //     int dp[] = new int [n];
    //     for(int i = 0; i<n; i++)
    //         dp[i] = -1;
        
    //     return solve(0, arr, dp, n);
    // }

//method 2: tabulation
    // public static int findMaxSum(int arr[], int n) {
    //     // code here
    //     int dp[] = new int[n];
    //     dp[0] = arr[0];

    //     for(int i = 1; i<n; i++){
    //         int Pick = arr[i];
    //         if(i>1)
    //             Pick+=dp[i-2];
    //         int nPick = dp[i-1];

    //         dp[i] = Math.max(Pick, nPick);
    //     }
    //     return dp[n-1];
    // }

//method 3: max space optimization

    public static int findMaxSum(int arr[], int n) {
        // code here
        int prev = arr[0];
        int prev2 = 0;

        for(int i = 1; i<n; i++){
            int take = arr[i];
            if(i>1)
            take+=prev2;
            int nTake = prev;

            int curr = Math.max(take, nTake);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int arr[] = new int[n];
        
        for(int i = 0; i<n; i++)
            arr[i] = sc.nextInt();
        
        System.out.print(findMaxSum(arr, n));
    }
}
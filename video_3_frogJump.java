import java.util.* ;
public class video_3_frogJump {
    public static int solve(int n, int dp[], int heights[]){
        if(n==0) return 0;
        if(dp[n] != -1) return dp[n];

        int step2 = Integer.MAX_VALUE;
        int step1 = solve(n-1, dp, heights)
        +Math.abs(heights[n]-heights[n-1]);

        if(n>1)
        step2 = solve(n-2, dp, heights)
        +Math.abs(heights[n]-heights[n-2]);

        return dp[n] = Math.min(step1, step2);

    }

    public static int frogJump(int n, int heights[]) {
        // Write your code here..
        int dp[] = new int[n+1];
        for(int i = 0; i<n+1; i++)
            dp[i] = -1;
        
        return solve(n-1, dp, heights);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        int arr[] = new int[n];
        for(int i = 0; i<n; i++)
            arr[i] = sc.nextInt();
        
        System.out.print(frogJump(n, arr));
    }

}
import java.io.*;

class Solution{
    private static long solve(int n, long dp[]){
        if(n<4) return 1;
        if(dp[n] != -1) return dp[n];

        long vertStk = solve(n-4, dp);
        long horizStk =  solve(n-1, dp);

        return dp[n] = vertStk+horizStk;
    }
    static long arrangeTiles(int N){
        // code here
        long dp[] = new long[N+1];
        for(int i = 0; i<=N; i++) dp[i] = -1;

        return solve(N, dp);
    }
}

class random_93_GFG_Number_of_ways{
    public static void main(String args[]) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());

        Solution sol = new Solution();
        System.out.println(sol.arrangeTiles(N));
    }
}
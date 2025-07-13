import java.util.*;

class Solution{
    public int minOperation(int n) {
        //code here.
        int dp[] = new int[n+1];
        Arrays.fill(dp, (int)1e9);

        dp[n] = 0;
        
        for(int i = n-1; i>=0; i--){
            int dbl = (int)1e9, one = (int) 1e9;
            if(i != 0 && 2*i <= n) dbl = 1+dp[2*i];
            if(i+1 <= n) one = 1+dp[i+1];

            dp[i] = Math.min(dbl, one);
        }
        return dp[0];
    }
    // public int minOperation(int n) {
    //     //code here.
    //     ArrayList<Integer> dp = new ArrayList<>
    //     (Collections.nCopies(n+1, (int)(1e9)));
        
    //     dp.set(n, 0);
        
    //     for(int i = n-1; i>=0; i--){
    //         int dbl = (int)1e9, one = (int) 1e9;
    //         if(i != 0 && 2*i <= n) dbl = 1+dp.get(2*i);
    //         if(i+1 <= n) one = 1+dp.get(i+1);

    //         dp.set(i, Math.min(dbl, one));
    //     }
    //     return dp.get(0);
    // }
}

@SuppressWarnings("unused")
class random_54_GFG_Minimum_Operations{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        Solution sol = new Solution();
        System.out.println(sol.minOperation(n));
    }
}
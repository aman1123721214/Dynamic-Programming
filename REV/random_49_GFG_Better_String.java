import java.util.*;
class Solution{
    private static long solve(String s){
        int n = s.length();
        long dp[] = new long[n+1];
        dp[0] = 1;

        HashMap<Character, Integer> last = new HashMap<>();
        for(int i = 1; i<=n; i++){
            dp[i] = 2*dp[i-1];

            if(last.containsKey(s.charAt(i-1)))
                dp[i] -= dp[last.get(s.charAt(i-1))];
            last.put(s.charAt(i-1), i-1);
        }
        return dp[n];
    }
    public static String betterString(String str1, String str2) {
        // Code here
        long len1 = solve(str1);
        long len2 = solve(str2);

        return (len1>=len2)?str1:str2;
    }
}

@SuppressWarnings("unused")
class random_49_GFG_Better_String{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        String str1 = sc.next();
        String str2 = sc.next();

        Solution solution = new Solution();
        System.out.println(solution.betterString(str1, str2));
    }
}
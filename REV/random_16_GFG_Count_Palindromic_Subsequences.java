import java.util.*;

class Solution {
    private int solve(int i, int j, String str, ArrayList<ArrayList<Integer>> dp) {
        if (i > j) return 0;
        if (i == j) return 1;
        
        if (dp.get(i).get(j) != -1) return dp.get(i).get(j);
        
        if (str.charAt(i) == str.charAt(j)) {
            dp.get(i).set(j, 1 + solve(i + 1, j, str, dp) + solve(i, j - 1, str, dp));
        } else {
            dp.get(i).set(j, solve(i + 1, j, str, dp) + solve(i, j - 1, str, dp) - solve(i + 1, j - 1, str, dp));
        }
        return dp.get(i).get(j);
    }
    
    int countPS(String s) {
        int n = s.length();
        ArrayList<ArrayList<Integer>> dp = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            ArrayList<Integer> row = new ArrayList<>(Arrays.asList(new Integer[n]));
            Arrays.fill(row.toArray(new Integer[n]), -1);
            dp.add(row);
        }
        return solve(0, n - 1, s, dp);
    }
}

@SuppressWarnings("unused")
class random_16_GFG_Count_Palindromic_Subsequences{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String str = sc.next();
        System.out.println(new Solution().countPS(str));
    }
}
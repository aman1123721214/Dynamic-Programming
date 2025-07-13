import java.util.Arrays;
import java.util.Scanner;

class Solution {
    public int bellNumber(int n) {
        // Code Here
        int prev[] = new int[14];
        int curr[] = new int[14];
        prev[0] = 1;

        for(int i = 2; i<=n; i++){
            curr[0] = prev[i-2];
            for(int j = 1; j<i; j++)
                curr[j] = prev[j-1]+curr[j-1];
            prev = Arrays.copyOf(curr, curr.length);
        }
        return prev[n-1];
    }
}

class random_99_GFG_Bell_Numbers{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System .in);
        int n = sc.nextInt();

        Solution obj = new Solution();

        System.out.print(obj.bellNumber(n));
    }
}
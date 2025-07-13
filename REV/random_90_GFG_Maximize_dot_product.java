import java.util.*;
import java.io.*;

class Solution {
	public static int maxDotProduct(int n, int m, int a[], int b[]) { 
		// Your code goes here
        ArrayList<ArrayList<Long>> dp = new ArrayList<>();
        
        for(int i = 0; i<=n; i++){
            ArrayList<Long> row = new ArrayList<>();
            for(int j = 0; j<=m; j++){
                if(j==0) row.add(0L);
                else if(i == 0) row.add(Long.MIN_VALUE);
                else 
                row.add(0L);
            }
            dp.add(row);
        }

        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=m; j++){
                long take = a[i-1]*b[j-1] + dp.get(i-1).get(j-1);
                long nTake = dp.get(i-1).get(j);

                dp.get(i).set(j, Math.max(take, nTake));
            }
        }
        return (int) (dp.get(n).get(m));
	} 
}

class random_90_GFG_Maximize_dot_product{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();

        int []a = new int[n];
        int []b = new int[m];

        for(int i = 0; i<n; i++) a[i] = sc.nextInt();
        for(int j = 0; j<m; j++) b[j] = sc.nextInt();

        Solution obj = new Solution();

        System.out.print(obj.maxDotProduct(n, n, a, b));

    }
}
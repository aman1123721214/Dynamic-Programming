import java.io.*;

class Solution {
    private static int solve(int i, int j, int dp[][], int arr[]){
        if(i == j) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int mini = (int)(1e9);
        for(int k = i; k<j; k++){
            int steps = arr[i-1]*arr[k]*arr[j]+
                solve(i, k, dp, arr)+solve(k+1, j, dp, arr);
            mini = Math.min(mini, steps);
        }       
        return mini;
    }
    
    int matrixMultiplication(int arr[]) {
        // code here
        int n = arr.length;
        int dp[][] = new int[n][n];
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                dp[i][j] = -1;
            }
        }

        return solve(1, n-1, dp, arr);
    }
}
@SuppressWarnings("unused")
class random_20_GFG_Matrix_Chain_Multiplication{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] str = (br.readLine()).trim().split(" ");

        int arr[] = new int[str.length];

        for(int i = 0; i<str.length; i++)
            arr[i] = Integer.parseInt(str[i]);

        Solution obj = new Solution();
        System.out.println(obj.matrixMultiplication(arr));
    }
}
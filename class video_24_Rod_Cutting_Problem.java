// import java.util.*;
// class video_24_Rod_Cutting_Problem{
//     public static int solve(int ind, int n, int price[], int dp[][]){
//         if(ind==0)  
//             return n*price[0];
//         if(dp[ind][n] != -1)  return dp[ind][n];
//         int not_cut = solve(ind-1, n, price, dp);
//         int cut = (int)(-1e9);
//         if(ind+1<=n)
//         cut = price[ind] + solve(ind, n-(ind+1), price, dp);

//         return dp[ind][n] = Math.max(cut, not_cut);
//     }
//     public static int cutRod(int price[], int n) {
//         //code here
//         int dp[][] = new int[n][n+1];
//         for(int row[]:dp) Arrays.fill(row, -1);
//         return solve(n-1, n, price, dp);
//     }

//     public static void main(String[] args) {
//         Scanner sc = new Scanner(System.in);
//         int n = sc.nextInt();
//         int price[]  = new int[n+1];
//         for(int i = 1; i<n; i++) price[i] = sc.nextInt();
//         System.out.print(cutRod(price, n));
//     }
// }
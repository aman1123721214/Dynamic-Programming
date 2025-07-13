// import java.util.*;
// class video_22_Coin_Change_3 {
//     public static boolean  solve(int ind, int k, int count, int target, int coins[]){
//         if(target==0 && count==k)   return true;
//         if(ind<0 || target<0)   return false;

//         boolean nTake = solve(ind-1, k, count, target, coins);
//         boolean take = solve(ind, k, count+1, target-coins[ind], coins);
    
//         return take||nTake;
//     }

//     public static boolean makeChanges(int N, int K, int target, int[] coins) {
//         // code here
//         return solve(N-1, K, 0, target, coins);
//     }

//     public static void main(String[] args) {
//         Scanner sc = new Scanner(System.in);
//         int n = sc.nextInt();
//         int k = sc.nextInt();
//         int target = sc.nextInt();

//         int coins[] = new int[n];
//         for(int i = 0; i<n; i++)    coins[i] = sc.nextInt();
//         System.out.print(makeChanges(n, k, target, coins));
//     }
// }
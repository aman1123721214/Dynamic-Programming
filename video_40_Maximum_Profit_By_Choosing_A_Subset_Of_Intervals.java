import java.util.*;
class video_40_Maximum_Profit_By_Choosing_A_Subset_Of_Intervals {
    public static int solve(int ind, int st1, int end1, int arr[][]){
        if(ind == arr.length)   return 0;
        int st2 = arr[ind][0];
        int end2 = arr[ind][1];
        
        int profit = 0;
        if(st1<st2 && end1<=st2)
        profit = Math.max(arr[ind][2]+solve(ind+1, st2, end2, arr),
        solve(ind+1, st1, end1, arr));

        else
        profit = solve(ind+1, st1, st2, arr);

        return profit;
    }
    public static int maximum_profit(int n, int[][] intervals) {
        // code here 
        return solve(0,-1, -1, intervals);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int intervals[][] = new int[n][3];
        for(int i = 0; i<n; i++){
            for(int j = 0; j<3; j++)
            intervals[i][j] = sc.nextInt();
        }

        System.out.print(maximum_profit(n, intervals));
    }
}
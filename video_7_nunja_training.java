// import java.util.*;
//class video_7_nunja_training {
//method 1: recursion

    // public static int solve(int day, int lastTask, int arr[][]){
    //     if(day == 0){
    //         int maxi = 0;
    //         for(int task = 0; task<3; task++){
    //             if(task!=lastTask)
    //             maxi = Math.max(maxi, arr[0][task]);
    //         }return maxi;
    //     }

    //     int maxi = 0;
    //     for(int task = 0; task<3; task++){
    //         if(task!=lastTask){
    //             int score = arr[day][task]+solve(day-1, task, arr);
    //             maxi = Math.max(maxi, score);
    //         }
    //     }
    //     return maxi;
    // }

    // public static int maximumPoints(int arr[][], int n) {
    //     // code here
    //     return solve(n-1, 3, arr);
    // }

//method 2: memoization
    // public static int solve(int day, int lastTask, int arr[][], int dp[][]){
    //     if(day == 0){
    //         int maxi = 0;
    //         for(int task = 0; task<3; task++){
    //             if(task!=lastTask)
    //             maxi = Math.max(maxi, arr[0][task]);
    //         }return maxi;
    //     }

    //     if(dp[day][lastTask] != -1) return dp[day][lastTask];

    //     int maxi = 0;
    //     for(int task = 0; task<3; task++){
    //         if(task!=lastTask){
    //             int score = arr[day][task]+solve(day-1, task, arr, dp);
    //             maxi = Math.max(maxi, score);
    //         }
    //     }
    //     return dp[day][lastTask] = maxi;
    // }
    // public static int maximumPoints(int arr[][], int n) {
    //     // code here
    //     int dp[][] = new int[n][4];
    //     for(int i = 0; i<n; i++){
    //         for(int j = 0; j<4; j++)
    //             dp[i][j] = -1;
    //     }
    //     return solve(n-1, 3, arr, dp);
    // }

//     public static void main(String[] args) {
//         Scanner sc = new Scanner(System.in);
        
//         int rows = sc.nextInt();

//         int[][] arr = new int[rows][3];
//         for(int i = 0; i<rows; i++){
//             for(int j = 0; j<3; j++){
//                 arr[i][j] = sc.nextInt();
//             }
//         }

//         System.out.print(maximumPoints(arr, rows));
//         sc.close();
//     }

// }
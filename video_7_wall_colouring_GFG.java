import java.util.*;
class video_7_wall_colouring_GFG{
    // public static int n, k;
    
    // public static int solve(int ind, int lastTask, 
    // int [][] cost, int dp[][]){
    //     if(ind==0){
    //         int min = (int)(1e9);
    //         for(int task = 0; task<k; task++){
    //             if(task!=lastTask){
    //                 min = Math.min(min, cost[ind][task]);
    //             }
    //         }
    //         return dp[ind][lastTask] = min;
    //     }

    //     if(dp[ind][lastTask]!=-1) return dp[ind][lastTask];
    //     int mini = (int)(1e9);

    //     for(int task = 0; task<k; task++){
    //         if(task!=lastTask){
    //             int ans = cost[ind][task];
    //             ans+=solve(ind-1, task, cost, dp);
    //             mini = Math.min(mini, ans);
    //         }
    //     }
    //     return dp[ind][lastTask] = mini;
    // }

	// public static int minCost(int [][] cost) {
	// 	//Write your code here
    //     n = cost.length;
    //     k = cost[0].length;
    //     if(n==0 || k==0) return -1;
    //     if(n>1 && k<=1) return -1;

    //     int dp[][] = new int[n][k+1];
    //     for(int row[]:dp)
    //         Arrays.fill(row, -1);

    //     return solve(n-1, k, cost, dp);
	// }
//method 2: max space optimization
	public static int minCost(int [][] cost) {
		//Write your code here
        int n=cost.length;
        int k=cost[0].length;
        if(n==1 && k==1) return cost[0][0];
        if(n==0 || k==0) return -1;
        if(n>1 && k<=1) return -1;
     
        int prev[] = new int[k];
        for(int lastTask=0;lastTask<k;lastTask++){
            int mini=(int)(1e9);
            for(int task=0;task<k;task++){
                if(task!=lastTask){
                    mini=Math.min(mini,cost[0][task]);
                }
            }prev[lastTask]=mini;
        }
        
        for(int walls=1;walls<n;walls++){
            int curr[] = new int[k] ;
            for(int lastTask=0;lastTask<k;lastTask++){
                int mini=(int)(1e9);
                for(int task=0;task<k;task++){
                    if(task!=lastTask){
                        int price=cost[walls][task];
                        price+=prev[task];
                        mini=Math.min(mini,price);
                    }
                }curr[lastTask]=mini;
            }prev = curr;
        }
        
        int ans=(int)(1e9);
        for(int it:prev)
        ans=Math.min(ans,it);
        return ans;
	}

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int k = sc.nextInt();
        int cost[][] = new int[n][k];

        for(int i = 0; i<n; i++){
            for(int j = 0; j<k; j++)
                cost[i][j] = sc.nextInt();
        }

        System.out.print(minCost(cost));
    }
}
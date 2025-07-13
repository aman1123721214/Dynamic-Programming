import java.util.*;
class Solution{
    public int climbStairs(int n){
        if(n<=2) return n;
        int p1 = 2, p2 = 1;
        int temp;
        for(int i = 3; i<=n; i++){
            temp = p1+p2;
            p2 = p1;
            p1 = temp;
        }
        return p1;
    }
};

class video_2_REV__Climbing_Stairs{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        Solution obj = new Solution();
        System.out.println(obj.climbStairs(n));
    }
}
import java.util.*;
class video_6_House_Robber_2 {
    public static int solve(ArrayList<Integer> arr,int n) {
        // code here
        int prev = arr.get(0);
        int prev2 = 0;

        for(int i = 1; i<n; i++){
            int take = arr.get(i);
            if(i>1)
            take+=prev2;
            int nTake = prev;

            int curr = Math.max(take, nTake);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
    public static int maxValue(int[] arr) {
        // code here
        int n = arr.length;
        if(n == 1) return arr[0];
        
        ArrayList<Integer> temp1 = new ArrayList<>();
        ArrayList<Integer> temp2 = new ArrayList<>();

        for(int i = 0; i<n; i++){
            if(i!=0) temp1.add(arr[i]);
            if(i!=n-1) temp2.add(arr[i]);
        }

        int ans1 = solve(temp1, n-1);
        int ans2 = solve(temp2, n-1);

        return Math.max(ans1, ans2);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int n = sc.nextInt();
        int arr[] = new int[n];

        for(int i = 0; i<n; i++){
            arr[i] = sc.nextInt();
        }

        System.out.print(maxValue(arr));
    }
}
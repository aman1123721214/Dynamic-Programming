import java.util.Scanner;
class Solution {
    long max_Books(int arr[], int n, int k) {
        // Your code here
        long ans = 0;
        long sum = 0;

        for(int i = 0; i<n; i++){
            if(arr[i]>k){
                sum = 0;
                continue;
            }
            sum+=arr[i];
            ans = Math.max(ans, sum);
        }
        return ans;
    }
}

@SuppressWarnings("unused")
class random_60_GFG_You_and_your_books{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();

        int arr[] = new int[n];
        for(int i = 0; i<n; i++) arr[i] = sc.nextInt();

        Solution sol = new Solution();
        System.out.println(sol.max_Books(arr, n, k));
    }
}
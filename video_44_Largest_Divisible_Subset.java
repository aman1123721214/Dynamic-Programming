import java.io.IOException;
import java.util.*;
class video_44_Largest_Divisible_Subset {
    public static List<Integer> LargestSubset(int n, int[] arr) {
        // Code here
        Arrays.sort(arr);
        int dp[] = new int[n], hash[] = new int[n];
        Arrays.fill(dp, 1);
        int ind = 0;
        int maxi = 1;
        for(int i = 0; i<n; i++){
            hash[i] = i;
            for(int j = 0; j<i; j++){
                if(arr[i]%arr[j] == 0){
                    if(1+dp[j]>dp[i]){
                        dp[i] = 1+dp[j];
                        hash[i] = j;
                        if(maxi<dp[i]){
                            ind = i;
                            maxi = dp[i];
                        }
                    }
                }
            }
        }
        
        List<Integer> ans = new ArrayList<>();
        ans.add(arr[ind]);
        while(ind != hash[ind]){
            ind = hash[ind];
            ans.add(arr[ind]);
        }
        Collections.reverse(ans);
        return ans;
    }

    public static void main(String[] args) throws IOException{
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int arr[] = new int[n];
        for(int i = 0; i<n; i++)
            arr[i] = sc.nextInt();
    System.err.println(LargestSubset(n, arr));
    }
}
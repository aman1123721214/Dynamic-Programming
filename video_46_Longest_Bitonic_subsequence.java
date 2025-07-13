import java.util.*;
class video_46_Longest_Bitonic_subsequence {
    public static int LongestBitonicSequence(int n, int[] nums) {
        // code here
        int dp1[] = new int[n]; Arrays.fill(dp1, 1);
        int dp2[] = new int[n]; Arrays.fill(dp2, 1);

        for(int i = 0; i<n; i++){
            for(int j = 0; j<i; j++){
                if(nums[i]>nums[j] && 1+dp1[j]>dp1[i])
                    dp1[i] = 1+dp1[j];
            }
        }
        
        if(dp1[nums.length-1] == nums.length) return 0;
        int maxi = 1;
        for(int i = n-1; i>=0; i--){
            for(int j = n-1; j>i; j--){
                if(nums[i]>nums[j] && 1+dp2[j]>dp2[i])
                    dp2[i] = 1+dp2[j];
                    if(dp1[i] != 1 && dp2[i] != 1)
                    maxi = Math.max(maxi, dp1[i]+dp2[i]);
            }
        }
        return maxi-1;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner (System.in);
        int n = sc.nextInt();
        int nums[] = new int[n];
        for(int i = 0; i<n; i++)
            nums[i] = sc.nextInt();
        
        System.out.println(LongestBitonicSequence(n, nums));
    }
}
import java.util.*;

class video_45_Longest_String_Chain{
    public static boolean checkPossible(String str1, String str2){
        if(str1.length() != str2.length()+1)    
            return false;
        int i = 0, j = 0;

        while(i<str1.length()){
            if(j<str2.length() && str1.charAt(i) == str2.charAt(j)){
                i++; j++;
            }
            else i++;
        }

        if(i == str1.length() && j == str2.length())
            return true;
        return false;
    }
    public static int longestChain(int N, String words[]){
     //code here
        int dp[] = new int[N];
        Arrays.sort(words, Comparator.comparing(s->s.length()));
        Arrays.fill(dp, 1);
        int maxi = 1;
        for(int i = 0; i<N; i++){
            for(int j = 0; j<i; j++){
                if(checkPossible(words[i], words[j])
                 && dp[i] < 1+dp[j]){
                    dp[i] = 1+dp[j];
                    maxi = Math.max(maxi, dp[i]);
                 }
            }
        }
        return maxi;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner (System.in);
        int N = sc.nextInt();
        String words[] = new String[N];

        for(int i = 0; i<N; i++){
            words[i] = sc.next();
        }

        System.out.print(longestChain(N, words));
    }
}
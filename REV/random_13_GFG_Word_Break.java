import java.util.*;
import java.io.*;
class Solution{
    private static boolean solve(String str, int ind, Set<String> st){
        if(ind==str.length()) return true;

        String temp = "";
        for(int i = ind; i<str.length(); i++){
            temp+=str.charAt(i);
            if(st.contains(temp)){
                if(solve(str, i+1, st)) return true;
            }
        }return false;
    }

    public static int wordBreak(int n, String s, ArrayList<String> dictionary ){
        //code here
        Set<String> st = new HashSet<>(dictionary);
        return solve(s, 0, st)?1:0;
    }
}

@SuppressWarnings("unused")
class random_13_GFG_Word_Break{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        ArrayList<String> dictionary = new ArrayList<String>();
        for(int i = 0; i<n; i++) {
            String p = sc.next();
            dictionary.add(p);
        }

        String s = sc.next();

        Solution obj = new Solution();
        System.out.print(obj.wordBreak(n, s, dictionary));
    }
}
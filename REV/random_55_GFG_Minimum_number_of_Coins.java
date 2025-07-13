import java.util.*;
class Solution{
    static List<Integer> minPartition(int N){
        // code here
        int currency[] = {2000,500,200,100,50,20,10,5,2,1};
        int i = 0, notes = 0;
        List<Integer> list = new ArrayList<>();

        while(N != 0){
            notes = N/currency[i];
            while(notes-- != 0)  list.add(currency[i]);
            N %= currency[i++];
        }
        return list;
    }
}

@SuppressWarnings("unused")
class random_55_GFG_Minimum_number_of_Coins{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();

        Solution sol = new Solution();
        List<Integer> list = new ArrayList<>();
        list = sol.minPartition(N);

        for(int it: list)
            System.out.print(it+" ");
    }
}
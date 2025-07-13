import java.util.*;
class video_44_All_subsets_printing {
    public static ArrayList<ArrayList<Integer>> ans = new ArrayList<>();
    public static Set<ArrayList<Integer>> st = new HashSet<>();

    public static void solve(int ind, int[] nums, ArrayList<Integer> list){
        if(ind == nums.length){
            Collections.sort(list);
            st.add(list);
            return;
        }

        list.add(nums[ind]);        //take
        solve(ind+1, nums, list);   

        list.remove(list.size()-1);          //nTake
        solve(ind+1, nums, list);
    }

    public static ArrayList<ArrayList<Integer>> printUniqueSubsets(int[] nums) {
        ArrayList<Integer> Alist = new ArrayList<>();
        solve(0, nums, Alist);

        Iterator<ArrayList<Integer>> it = st.iterator();
        while(it.hasNext())
            ans.add(it.next());
        st.clear();

        return ans;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner (System.in);
        int n = sc.nextInt();
        int nums[] = new int[n];

        for(int i = 0; i<n; i++)
            nums[i] = sc.nextInt();
        
        ArrayList<ArrayList<Integer>> list = printUniqueSubsets(nums);
        Iterator<ArrayList<Integer>> out_it = list.iterator();

        while(out_it.hasNext()){
            //ArrayList<Integer> in_list = out_it.next();
            Iterator<Integer> in_it = out_it.next().iterator();
            while(in_it.hasNext()){
                System.out.print(in_it.next()+" ");
            }
            System.out.println();
        }
    }
}
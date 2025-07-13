class video_8_longest_path_in_grid {
    private static int n, m, ans;
    private static int[][] mat;

    private static boolean isValid(int x, int y) {
        return x>=0 && y>=0 && x<n && y<m && mat[x][y] == 1;
    }

    private static void helper(int i, int j, int di, int dj, int step) {
        if (!isValid(i, j)) return;
        if (i == di && j == dj) {
            ans = Math.max(ans, step);
            return;
        }
        
        mat[i][j] = 0; //mark it visited
        helper(i+1, j, di, dj, step+1); // down
        helper(i-1, j, di, dj, step+1); //up
        helper(i, j+1, di, dj, step+1); //right
        helper(i, j-1, di, dj, step+1); //left
        mat[i][j] = 1;// unvisit it, for backtracking
    }
    
    public static int longestPath(int[][] _mat,int _n,int _m,int xs,int ys,int xd,int yd) {
        mat = _mat; n = _n; m = _m; //for simplicity, in inverview pass in method
        ans = Integer.MIN_VALUE;
        helper(xs, ys, xd, yd, 0);
        return ans == Integer.MIN_VALUE ? -1 : ans;
    }
}
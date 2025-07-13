// #include<bits/stdc++.h>
// using namespace std;
// class Solution
// {       // 1->source	2->dest		3->blank cell		0->wall    
//     public:
// 	void solve(int x, int y, vector<vector<int>>& mat){
// 		if(mat[x][y] == 3 || mat[x][y] == 2) mat[x][y] = 1;
// 		else return;

// 		int n = mat.size();
// 		//up
// 		if(x-1>=0) solve(x-1, y, mat);
// 		//down
// 		if(x+1<n) solve(x+1, y, mat);
// 		//left
// 		if(y-1>=0) solve(x, y-1, mat);
// 		//right
// 		if(y+1<n) solve(x, y+1, mat);
// 		return;
// 	}
//     bool is_Possible(vector<vector<int>>& grid) 
//     {
//         //code here
// 		int n = grid.size(), sx = -1, sy = -1, dx = -1, dy = -1;
// 		vector<vector<int>> mat = grid;

// 		for(int i = 0; i<n; i++){
// 			for(int j = 0; j<n; j++){
// 				if(mat[i][j] == 1){
// 					sx = i, sy = j;
// 					mat[i][j] = 3;
// 				}
// 				if(grid[i][j] == 2)
// 					dx = i, dy = j;
// 			}
// 		}
// 		solve(sx, sy, mat);
// 		return mat[dx][dy] == 1;
//     }
// };

// int main(){
// 	int tc;
// 	cin >> tc;
// 	while(tc--){
// 		int n;
// 		cin >> n;
// 		vector<vector<int>>grid(n, vector<int>(n, -1));
// 		for(int i = 0; i < n; i++){
// 			for(int j = 0; j < n; j++){
// 				cin >> grid[i][j];
// 			}
// 		}
// 		Solution obj;
// 		bool ans = obj.is_Possible(grid);
// 		cout << ((ans) ? "1\n" : "0\n");
// 	}
// 	return 0;
// }
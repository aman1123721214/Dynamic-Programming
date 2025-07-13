#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:int t[1005][1005] ;
	int Solve(int *A, int i, int N, int K)
	{
	    if(K==0) return 0 ;
	    
	    if(i==N) return 1e9;
	    
	    if(t[i][K]!=-1)
	    return t[i][K] ;
	    
	    int Ans = 1e9 ;
	    
	    for(int j=i+1; j<N ; j++)
	    {
	        if(A[j] >= A[i]){
	            Ans = min(Ans, A[j] + Solve(A,j,N,K-1)) ;
	        }
	    }
	    
	    return t[i][K] = Ans ;
	}

	int minSum(int arr[], int N, int K) 
	{ 
        
		// Your code goes here
		memset(t,-1,sizeof(t)) ;
        int Ans = 1e9 ;
        for(int i=0 ; i<=N-K; i++)
        {
            Ans = min(Ans, arr[i] + Solve(arr,i,N,K-1)); 
        }
		if(Ans >= 1e9) return -1;
		return Ans ;
	} 
};

int main(){
    int n, k;
    cin>>n>>k;

    int *arr = new int[n];
    for(int i = 0; i<n; i++) cin>>arr[i];

    Solution obj;
    cout<<obj.minSum(arr, n, k);

    return 0;
}
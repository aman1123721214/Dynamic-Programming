#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int offerings(int N, int arr[]){
        // code here
        vector<int> left(N, 1);
        for(int i = 1; i<N; i++){
            if(arr[i]>arr[i-1])
                left[i] = left[i-1]+1;
        }

        vector<int> right(N, 1);
        for(int i = N-2; i>=0; i--){
            if(arr[i]>arr[i+1])
                right[i] = right[i+1]+1;
        }

        int sum = 0;
        for(int i = 0; i<N; i++)
        sum+=max(left[i], right[i]);

        return sum;
    }
};

int main(){
    int N;  cin>>N;
    int *arr = new int[N];

    for(int i = 0; i<N; i++) cin>>arr[i];
    Solution obj;
    cout<<obj.offerings(N, arr);

    return 0;
}
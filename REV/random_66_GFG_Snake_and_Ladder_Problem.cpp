#include<bits/stdc++.h>
using namespace std;


class Solution{
public:
    int minThrow(int N, int arr[]){
        // code here
        unordered_map<int, int> ladder, snake;
        for(int i = 0; i<2*N; i+=2){
            if(arr[i]<arr[i+1]) ladder[arr[i]] = arr[i+1];
            else snake[arr[i]] = arr[i+1]; 
        }

        // queue = {step, loc}
        queue<pair<int, int>> q;
        q.push({0, 1});

        while(!q.empty()){
            int step = q.front().first;
            int loc = q.front().second;
            q.pop();

            if(loc == 30) return step;
            if(loc>30) continue;

            for(int throws = 1; throws<=6; throws++){
                int newLoc = loc+throws;

                if(snake.find(newLoc) != snake.end())
                    q.push({step+1, snake[newLoc]});
                else if(ladder.find(newLoc) != ladder.end())
                    q.push({step+1, ladder[newLoc]});
                else q.push({step+1, newLoc});
            }
        }
    }
};

int main(){
    int n; cin>>n;
    int *arr = new int[n];

    for(int i = 0; i<n; i++) cin>>arr[i];

    Solution obj;
    cout<<obj.minThrow(n, arr);
    return 0;
}
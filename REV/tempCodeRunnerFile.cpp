class Solution{
public:
    int totalWays(int n, vector<int>capacity) {
        // code here
        int mod = 1e9+7;
        int prod = capacity[0];
        sort(capacity.begin(), capacity.end());

        for(int i = 1; i<n; i++){
            prod = (prod * (capacity[i]-i))%mod;
            if(!prod) return 0;
        }
        return prod;
    }
};
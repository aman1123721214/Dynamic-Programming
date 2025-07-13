#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool backtrack(int ind, vector<int> &arr, vector<int> &subsetSums, int targetSum, int k) {
        
        if (ind == arr.size()) {
            return true;
        }

        for (int i = 0; i < k; i++) {

            if (subsetSums[i] + arr[ind] > targetSum) continue;
            if (i > 0 && subsetSums[i] == subsetSums[i - 1]) continue;

            subsetSums[i] += arr[ind];

            if (backtrack(ind + 1, arr, subsetSums, targetSum, k)) {
                return true;
            }
            subsetSums[i] -= arr[ind];
        }

        return false;
    }

public:
    bool isKPartitionPossible(vector<int> &arr, int k) {
        int totalSum = 0;
        for (int num : arr) totalSum += num;

        if (totalSum % k != 0) return false;

        int targetSum = totalSum / k;
        sort(arr.begin(), arr.end(), greater<int>());

        vector<int> subsetSums(k, 0);

        return backtrack(0, arr, subsetSums, targetSum, k);
    }
};

// Driver code
int main() {
    vector<int> arr = {2, 1, 4, 5, 6};
    int k = 3;

    Solution solution;
    cout << (solution.isKPartitionPossible(arr, k) ? "true" : "false") << endl;

    return 0;
}
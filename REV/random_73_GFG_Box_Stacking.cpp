#include<bits/stdc++.h>
using namespace std;

struct Box{
    int length, width, height;
};

class Solution {
  private:
    //generate valid orientations for single box
    vector<Box> generateValidOrientation(int l, int b, int h){
        vector<Box> orientations = {
            {l, b, h}, {b, l, h},
            {l, h, b}, {h, l, b},
            {b, h, l}, {h, b, l}
        };

        vector<Box> validOrient;
        for(const auto &box : orientations){
            if(box.length>=box.width) validOrient.push_back(box);
        }
        return validOrient;
    }

    //generate valid orientations for multiple box
    vector<Box> generateAllorientation(vector<int> &length, vector<int> &width, vector<int> &height){
        int n = length.size();
        vector<Box> allOrient;

        for(int i = 0; i<n; i++){
            vector<Box> validOrient = generateValidOrientation(length[i], width[i], height[i]);
            allOrient.insert(allOrient.end(), validOrient.begin(),  validOrient.end());
        }
        return allOrient;
    }

    bool canPlaceOnTop(const Box& a, const Box& b){
        return (a.length<b.length && a.width<b.width);
    }

    //calculate maxHeight for each index ind as base
    int maxheightsFromBoxes(int ind, vector<Box> &boxes, vector<int> &dp){
        if(dp[ind] != -1) return dp[ind];
        int maxHeight = boxes[ind].height;

        for(int i = 0; i<ind; i++){
            if(canPlaceOnTop(boxes[ind], boxes[i])){
                int heightWithI = boxes[ind].height+maxheightsFromBoxes(i, boxes, dp);
                maxHeight = max(maxHeight, heightWithI);        
            }
        }
        return dp[ind] = maxHeight;
    }

  public:
    /*The function takes an array of heights, width and
    length as its 3 arguments where each index i value
    determines the height, width, length of the ith box.
    Here n is the total no of boxes.*/
    int maxHeight(vector<int> &height, vector<int> &width, vector<int> &length) {
        // Your code here
        vector<Box> allOrient = generateAllorientation(length, width, height);
        
        sort(allOrient.begin(), allOrient.end(), [](const Box& a, const Box& b){
            return (a.length*a.width > b.length*b.width);
        });

        int n = allOrient.size();
        vector<int> dp(n, -1);
        
        int ans = 0;
        for(int i = 0; i<n; i++){
            ans = max(ans, maxheightsFromBoxes(i, allOrient, dp));
        }
        return ans;
    }
};


int main(){
    string str;
    getline(cin, str);
    stringstream ss(str);

    vector<int> height;
    int num;
    while(ss>>num)
        height.push_back(num);

    getline(cin, str);
    stringstream ss1(str);
    vector<int> length;
    while(ss1>>num) length.push_back(num);

    getline(cin, str);
    stringstream ss2(str);
    vector<int> width;
    while(ss2>>num) width.push_back(num);

    Solution obj;
    cout<<obj.maxHeight(height, width, length);

    return 0;
}
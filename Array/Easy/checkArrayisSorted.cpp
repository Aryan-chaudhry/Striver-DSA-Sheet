#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(vector<int>& nums) {
        // steps to solve this problem
        // maintain the initial state from where se start the rotation
        // check is initial state is sorted then return true else return false

        vector<int>initial;
        int track = -1;
        
        for(int i=0; i<nums.size()-1; i++){
            if(nums[i] > nums[i+1]){
                track = i+1;
                break;
            }
        }
        
        if(track == -1){
            // array is already in sorted form
            return true;
        }

        for(int i=track; i<nums.size(); i++){
            initial.push_back(nums[i]);
        }

        for(int i=0; i<track; i++){
            initial.push_back(nums[i]);
        }

        for(int i=0; i<initial.size()-1; i++){
            if(initial[i] > initial[i+1]){
                return false;
            }
        }
        return true;
    }
};

int main(){
    vector<int>nums = {3,4,5,1,2};

    Solution s;
    bool ans = s.check(nums);
    if(ans) cout << "true" << endl;
    else cout << "false" << endl;
}
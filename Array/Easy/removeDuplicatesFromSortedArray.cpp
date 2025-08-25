#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0, j=i+1;
        while(j < nums.size()){
            // 2 cases
            // no are equal
            if(nums[i] == nums[j]){
                j++;
            }
            // no is different
            else{
                i++;
                nums[i] = nums[j];
            }

        }
        return i+1;
    }
};

int main(){
    vector<int>nums = {1,1,2};

    Solution s;
    int ans = s.removeDuplicates(nums);
    cout << ans << "   ";

    cout << "[";

    for(auto no : nums){
        cout << no << " ";
    }
    cout << "]";
}
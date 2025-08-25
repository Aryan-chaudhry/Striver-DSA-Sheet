#include<bits/stdc++.h>
using namespace std;

void moveZeroes(vector<int>& nums) {
        int i=0, j=0;
        while(j < nums.size()){
            if(nums[j] != 0){
                nums[i++] = nums[j];
            }
            j++;
        }

        for(int j=i; j<nums.size(); j++){
            nums[j] = 0;
        }
    }

int main(){
    vector<int>nums = {0,1,0,3,12};

    moveZeroes(nums);

    for(auto no : nums){
        cout << no << " ";
    }
}
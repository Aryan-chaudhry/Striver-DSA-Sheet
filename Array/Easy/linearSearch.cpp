#include<bits/stdc++.h>
using namespace std;

bool linearSearch(vector<int>&nums, int target){
    

    for(int i=0; i<nums.size(); i++){
        if(nums[i] == target){
            return i;
        }
    }
    return -1;
}

int main(){
    vector<int>nums = {3,2,1,4,5};
    int target = 4;

    bool ans = linearSearch(nums, target);
    cout << ans << endl;
}
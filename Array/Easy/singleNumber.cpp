#include<bits/stdc++.h>
using namespace std;

int singleNumber(vector<int>& nums) {
    int num = 0;
    for(int i=0; i<nums.size(); i++){
        num ^= nums[i];
    }
    return num;
}

int main(){
    vector<int>nums = {1,2,2,3,3,4,4};
    int ans = singleNumber(nums);
    cout << ans << endl;
}
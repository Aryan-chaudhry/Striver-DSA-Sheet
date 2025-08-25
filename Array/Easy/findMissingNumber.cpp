#include<bits/stdc++.h>
using namespace std;

int getNum(vector<int>&nums){
    int sum = accumulate(nums.begin(), nums.end(), 0);
    int n = nums.size();
    int total = n*(n+1)/2;
    return total-sum;
}

int main(){
    vector<int>nums = {3,0,2};
    int ans = getNum(nums);
    cout<< ans << endl;
}
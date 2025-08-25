#include<bits/stdc++.h>
using namespace std;

int getLargestElement(int nums[], int n){
    

    int maxi = INT_MIN;

    for(int i=0; i<n; i++){
        maxi = max(maxi, nums[i]);
    }

    return maxi;
}

int main(){
    int nums[] = {1,2,9,-1,0};
    int n = sizeof(nums)/sizeof(nums[0]);

    int Ans = getLargestElement(nums, n);
    cout << Ans << endl;
}
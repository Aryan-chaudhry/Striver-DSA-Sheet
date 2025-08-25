#include<bits/stdc++.h>
using namespace std;

int largestElement(vector<int>&nums){
    int maxi = INT_MIN;

    for(auto no : nums){
        maxi = max(maxi, no);
    }

    return maxi;
}

int secondLargestElement(vector<int>&nums, int &largest){
    int Smaxi = INT_MIN;

    for(auto no : nums){
        if(no != largest){
            Smaxi = max(Smaxi, no);
        }
    }

    return Smaxi == INT_MIN ? -1 : Smaxi;
}

int main(){
    vector<int>nums= {-2,-1};

    int maxi = largestElement(nums);
    int Smaxi = secondLargestElement(nums, maxi);
    cout << Smaxi;
}
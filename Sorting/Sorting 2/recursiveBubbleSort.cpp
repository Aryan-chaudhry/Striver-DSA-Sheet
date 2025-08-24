#include<bits/stdc++.h>
using namespace std;

void RecursiveBubbleSort(vector<int>&arr, int itr){
    // base case
    if(itr >= arr.size()-1) return;

    for(int i=0; i<arr.size()-itr-1; i++){
        if(arr[i+1] <= arr[i]){
            swap(arr[i+1], arr[i]);
        }
    }

    RecursiveBubbleSort(arr, itr+1);

    // Time Complexity O(n^n)
    // space Complexity O(n)
}

int main(){
    vector<int>arr = {4,3,1,2,5};

    RecursiveBubbleSort(arr, 0);

    for(auto no : arr){
        cout << no << " ";
    }
}
#include<bits/stdc++.h>
using namespace std;

int findPivot(vector<int>&arr, int st, int end){
    
    int pv = arr[st];
    int left = st;
    int right = end;

    while(left < right){

        while(arr[left] <= pv && left <= end-1){ // dont go to end becuase i < j condition
            left++;
        }

        while(arr[right] > pv && right >= st+1){ // dont go to st because i < j condition
            right--;
        }

        if(left < right){
            swap(arr[left], arr[right]);
        }
    }
    swap(arr[st], arr[right]);
    return right;
}

void quickSort(vector<int>&arr, int st, int end){
    if(st >= end) return;

    int pivotIndex = findPivot(arr, st, end);
    quickSort(arr, st, pivotIndex-1);
    quickSort(arr, pivotIndex+1, end);
}

int main(){
    vector<int>arr = {4,2,3,1,5};

    int st = 0;
    int end = arr.size()-1;
    
    quickSort(arr, st, end);

    for(auto no : arr){
        cout << no << " ";
    }

    // Time Complexityy O(nlogn)
    // space Complexity O(n) --> recursive call stack
}
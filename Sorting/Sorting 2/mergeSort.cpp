#include<bits/stdc++.h>
using namespace std;

void merge(vector<int>&arr, int st, int mid, int end, vector<int>&ans){
    int i = st;
    int j=mid+1;
    int k = st;

    while(i <= mid && j <= end){
        if(arr[i] < arr[j]){
            ans[k++] = arr[i++];
        }
        else{
            ans[k++] = arr[j++];
        }
    }

    while(i <= mid){
        ans[k++] = arr[i++];
    }

    while(j <= end){
        ans[k++] = arr[j++];
    }

    for(int i=st; i<=end; i++){
        arr[i] = ans[i];
    }

}

void mergeSort(vector<int>&arr, int st, int end, vector<int>&ans){
    if(st >= end) return;

    int mid = st + ((end - st) >> 1);

    mergeSort(arr, st, mid, ans);
    mergeSort(arr, mid+1, end, ans);
    merge(arr, st, mid, end, ans);
}


int main(){
    vector<int>arr = {4,3,1,2,5};

    int st = 0;
    int end = arr.size()-1;
    vector<int>ans(arr.size());

    mergeSort(arr, st, end, ans);

    for(auto no : arr){
        cout << no << " ";
    }

    // Time Complexity O(nlogn)
    // space Complexity O(n)
    
}
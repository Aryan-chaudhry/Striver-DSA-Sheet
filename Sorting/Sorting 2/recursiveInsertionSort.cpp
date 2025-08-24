#include<bits/stdc++.h>
using namespace std;

void recursiveInsertionSort(vector<int>&arr, int i){
    // base case
    if(i >= arr.size()) return;

    int key = arr[i];
    int j=i-1;

    while(j >= 0 && arr[j] >= key){
        arr[j+1] = arr[j];
        // yha bhul jata hu ki j ko decrement bhi karna hai
        j--;
    }
    arr[j+1] = key;

    recursiveInsertionSort(arr, i+1);

    // Time Complexity  O(n*n)
    // space Complexity O(n)
}

int main(){
    vector<int>arr = {4,2,3,1,5};
    

    recursiveInsertionSort(arr, 1);

    
    for(auto no : arr){
        cout << no << " ";
    }
}
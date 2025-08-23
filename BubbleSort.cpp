#include<bits/stdc++.h>
using namespace std;

void bubbleSort(int arr[], int n){

    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(arr[j+1] < arr[j]){
                swap(arr[j+1], arr[j]);
            }
        }
    }

    //  After 1st iteration we get 1st maximum element
    // no of iteration is size-1
    // no of comparision (size*size-1)/2
    // Time Complexity  O(n*n)
    // space Complexity O(1)
}

int main(){
    int n;
    cin >> n;

    int arr[n];

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    bubbleSort(arr, n);

    for(auto no : arr){
        cout << no << " ";
    }
}
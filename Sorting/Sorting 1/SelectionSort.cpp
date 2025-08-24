#include<bits/stdc++.h>
using namespace std;

void SelectionSort(int arr[], int n){

    for(int itr = 0; itr<n-1; itr++){
        int minIndex = itr;
        for(int i=itr+1; i<n; i++){
            if(arr[i] < arr[minIndex]){
                minIndex = i;
            }
        }
        swap(arr[itr], arr[minIndex]);
    }

    // After 1st iteration we get --> 1st min Element
    // No of iteration --> size-1
    // No of Comparision --> (size*size-1)/2
    // Time Complexity  --> O(n*n)
    // space Complexity --> O(1)
}

int main(){
        int n;
        cin >> n;

        int arr[n];


        for(int i=0; i<n; i++){
            cin >> arr[i];
        }

        SelectionSort(arr, n);

        for(int i=0; i<n; i++){
            cout << arr[i] << " ";
        }

        cout << "\n";
   
}
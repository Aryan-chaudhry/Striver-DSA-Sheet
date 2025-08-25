#include<bits/stdc++.h>
using namespace std;

void findUnion(vector<int>&arr1, int i, vector<int>&arr2, int j, vector<int>&ans){

    while(i < arr1.size() && j < arr2.size()){
        if(arr1[i] == arr2[j]){
            ans.push_back(arr1[i]);
            i++;
            j++;
        }
        else if(arr1[i] < arr2[j]){
            i++;
        }
        else{
            j++;
        }
    }
}

int main(){
    vector<int>ans;

    vector<int>arr1 = {2,3,4,5,6};
    vector<int>arr2 = {1,2,3,4};

    findUnion(arr1, 0, arr2, 0, ans);

    for(auto no : ans){
        cout << no << " ";
    }
}
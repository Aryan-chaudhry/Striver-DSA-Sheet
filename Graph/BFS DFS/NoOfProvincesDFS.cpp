#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solveUsingDFS(int src, unordered_map<int,bool>&visited, vector<vector<int>>&isConnected){
       visited[src] = true;

       for(int nbr=0; nbr<isConnected[src].size(); nbr++){
            if(isConnected[src][nbr] == 1 && !visited[nbr]){
                solveUsingDFS(nbr, visited, isConnected);
            }
       }        
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int noOfComponent = 0;
        unordered_map<int, bool>visited;

        for(int src=0; src<isConnected.size(); src++){
            if(!visited[src]){
                solveUsingDFS(src, visited, isConnected);
                noOfComponent++;
            }
        }
        return noOfComponent;
    }
};

int main(){
    Solution s;
    vector<vector<int>> isConnected = {{1,1,0},{1,1,0},{0,0,1}};
    int ans = s.findCircleNum(isConnected);
    cout << ans << endl;
}
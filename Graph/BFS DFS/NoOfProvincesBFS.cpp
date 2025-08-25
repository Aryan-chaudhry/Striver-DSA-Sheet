#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solveUsingBFS(int src, unordered_map<int,bool>&visited, vector<vector<int>>&isConnected){
        queue<int>q;

        // maintain initial state
        q.push(src);
        visited[src] = true;

        // main logic
        while(!q.empty()){
            auto frontNode = q.front();
            q.pop();

            // go to its neighbour
            for(int nbr=0; nbr<isConnected[src].size(); nbr++){
                if(isConnected[frontNode][nbr] == 1 && !visited[nbr]){
                    q.push(nbr);
                    visited[nbr] = true;
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int noOfComponent = 0;
        unordered_map<int, bool>visited;

        for(int src=0; src<isConnected.size(); src++){
            if(!visited[src]){
                solveUsingBFS(src, visited, isConnected);
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
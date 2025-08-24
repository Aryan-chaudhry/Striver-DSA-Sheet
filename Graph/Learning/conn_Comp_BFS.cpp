#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:


    vector<int> solveUsingBFS(int src, unordered_map<int,bool>&visited, unordered_map<int, list<int>>&adj){
        queue<int>q;
        vector<int>ans;
        
        // maintain initial state
        q.push(src);
        visited[src] = true;
        
        // main  logic
        
        while(!q.empty()){
            auto frontNode = q.front();
            q.pop();
            
            ans.push_back(frontNode);
            
            // go to its neighbour
            for(auto nbr : adj[frontNode]){
                if(!visited[nbr]){
                    visited[nbr] = true;
                    q.push(nbr);
                }
            }
        }
        
        return ans;
        
    }
    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
        // lets make adjacency list
        unordered_map<int, list<int>>adj;
        
        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        // i have make undirected graph 
        
        unordered_map<int, bool>visited;
        vector<vector<int>>ans;
        
        for(int src = 0; src < V; src++){
            if(!visited[src]){
                auto temp = solveUsingBFS(src, visited, adj);
                ans.push_back(temp);
            }
        }
        return ans;
    }
};

int main(){
    Solution g;
    int V = 5;
    vector<vector<int>>edges = {{0,1}, {2,1}, {3,4}};

    auto ans = g.getComponents(V, edges);

    for(int i=0; i<ans.size(); i++){
        cout << "[";
        for(int j=0; j<ans[i].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << "]" << endl;
    }

    // Time Complexity O(V+E)
    // space Complexity O(V+E)
}

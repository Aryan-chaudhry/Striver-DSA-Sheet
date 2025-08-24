#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    
    void solveUsingDFS(int src, unordered_map<int,bool>&visited, unordered_map<int, list<int>>&adj, vector<int>&temp){
        visited[src] = true;
        temp.push_back(src);
        
        for(auto nbr : adj[src]){
            if(!visited[nbr]){
                solveUsingDFS(nbr, visited, adj, temp);
            }
        }
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
                vector<int>temp;
                solveUsingDFS(src, visited, adj, temp);
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
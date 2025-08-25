#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool bfs(int src, queue<int>&q, unordered_map<int,list<int>>&adj, unordered_map<int,bool>&visited, unordered_map<int,int>&parent ){
        // maintian initial state
        q.push(src);
        visited[src] = true;
        parent[src] = -1;
        
        // main logic
        while(!q.empty()){
            auto Node = q.front();
            q.pop();
            
            // go to its neighbour
            for(auto nbr : adj[Node]){
                if(!visited[nbr]){
                    q.push(nbr);
                    visited[nbr] = true;
                    parent[nbr] = Node;
                }
                else if(visited[nbr] == true && nbr != parent[Node]){
                    return true;
                }
            }
        }
        return false;
    }
    
    bool isCycle(int V, vector<vector<int>>& edges) {
        unordered_map<int, list<int>>adj;
        
        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        unordered_map<int,bool>visited;
        unordered_map<int,int>parent;
        
        queue<int>q;
        
 
        for(int src = 0; src<V; src++){
            if(!visited[src]){
                bool ans = bfs(src, q, adj, visited, parent);
                if(ans == true) return true;
            }
        }
        return false;
    }
};
int main(){
    int V=4, E=4;
    vector<vector<int>>edges = {{0,1}, {0,2}, {1,2}, {2,3}};

    Solution s;
    bool ans = s.isCycle(V,edges);
    if(ans == true){
        cout << "true" << endl;
    }
    else{
        cout << "false" << endl;
    }
    return 0;
}
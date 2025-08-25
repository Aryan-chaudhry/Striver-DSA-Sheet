#include<bits/stdc++.h>
using namespace std;


class Solution {
  public:
    bool DFS(int src, int parent, unordered_map<int, bool>&visited, unordered_map<int, list<int>>&adj){
        visited[src] = true;
        
        // go to neighbour
        for(auto nbr : adj[src]){
            if(!visited[nbr]){
                bool ans = DFS(nbr, src, visited, adj);
                if(ans == true) return true;
            }
            else{
                // it is visited 
                if(nbr != parent){
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
       int parent = -1;
       
       for(int src=0; src<V; src++){
           if(!visited[src]){
               bool ans = DFS(src, parent, visited, adj);
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
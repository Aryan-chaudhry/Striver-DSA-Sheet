#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int minTimeToRot = 0;
        int timer = 0;

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>>visited(m, vector<bool>(n, false));
        queue< pair<int, pair<int,int>>>q; // {min Time to rott, {i,j}};

        // i can move in 4 direction
        int di[4] = {-1, 0, 1, 0};
        int dj[4] = {0, 1, 0, -1};

        // maintain initial state

        // jitne bhi sade hue oranges hai unhe queue me daal do
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 2 && visited[i][j] == false){// rotten
                    q.push({timer, {i,j}});
                    visited[i][j] = true;
                }
            }
        }

        // main logic

        while(!q.empty()){
            auto frontNode = q.front();
            q.pop();

            int time = frontNode.first;
            int i = frontNode.second.first;
            int j = frontNode.second.second;

            minTimeToRot = max(minTimeToRot, time);

            // go to its neighbour
            for(int nbr=0; nbr<4; nbr++){
                int newi = di[nbr] + i;
                int newj = dj[nbr] + j;

                // check karo agar ke valid coordinated hai and yha par frsh oranges hai to hi me enko sadaunga
                if(newi >= 0 && newi < m && newj >=0 && newj < n && grid[newi][newj] == 1 && visited[newi][newj] == false){
                    q.push({time+1, {newi, newj}});
                    visited[newi][newj] = true;
                    grid[newi][newj] = 2; // ye important hai
                }
            }
        }

        // mujhe kais e pata chalega ki sare orange sad chuke hai , fresh oranges ko count karlo
        int freshOranges = 0;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1){
                    freshOranges++;
                }
            }
        }
        return freshOranges == 0 ? minTimeToRot : -1;
    }
};

int main(){
    vector<vector<int>>grid = {{2,1,1},{1,1,0},{0,1,1}};

    Solution s;
    int Ans = s.orangesRotting(grid);
    cout << Ans << endl;

}
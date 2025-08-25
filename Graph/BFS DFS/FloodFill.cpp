#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();

        queue< pair<pair<int,int>, int> >q;
        vector<vector<bool>>visited(m, vector<bool>(n, false));

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        // maintian initial state
        int orgColor = image[sr][sc];

        q.push({{sr, sc},orgColor});
        image[sr][sc] = color;
        visited[sr][sc] = true;

        // lets start our main logic
        while(!q.empty()){
            auto frontNode = q.front();
            int scr = frontNode.first.first;
            int scy = frontNode.first.second;
            int mycolor = frontNode.second;

            // so lets go to neighbour
            for(int i=0; i<4; i++){
                int nscr = dr[i] + scr;
                int nscy = dr[i] + scy;
            }
        }
    }
};

int main(){
    vector<vector<int>>image = {{1,1,1},{1,1,0},{1,0,1}};
    int sr = 1;
    int sc = 1;
    int color = 2;

    Solution s;
    s.floodFill(image, sr, sc, color);

    for(int i=0; i<image.size(); i++){
        cout << "[";
        for(int j=0; j<image[i].size(); j++){
            cout << j << " ";
        }
        cout << "]" << endl;
    }


}
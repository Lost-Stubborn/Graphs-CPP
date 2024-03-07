#include <bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>> grid, vector<vector<int>>& vis,int r, int c) {
    
    vis[r][c] = 1;
    queue<pair<int,int>> q;
    q.push({r,c});
    while(!q.empty()) {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();


    }
}

int numIslands(vector<vector<int>> grid) {
    int m = grid.size();
    int n = grid[0].size();

    vector<vector<int>> vis(n, vector<int>(m,0));
    int count = 0;
    for(int r=0; r<m; r++) {
        for(int c=0; c<n; c++) {
            if(!vis[r][c]) {
                count++;
                bfs(grid,vis,r,c);
            }
        }
    }
}

void display(vector<int> adj[], int n) {
    for(int i=1;i<=n;i++) {
        cout << i << " -> ";
        for(auto it : adj[i]){
            cout << it << ",";
        }
        cout << endl;
    }
}

int main() {

    int n, m;
    cin >> n >> m;
    vector<int> adj[n+1];

    for(int i=0; i<m; i++) {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    //display
    display(adj,n);
    return 0;
}
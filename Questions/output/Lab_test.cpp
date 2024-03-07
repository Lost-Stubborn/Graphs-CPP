#include <bits/stdc++.h>
using namespace std;

class Graph {
    vector<vector<int>> adj;
    int v;
    public :
    Graph() {

    }

    int createGraph() {
        int e;
        cin >> this->v >> e;
        adj = vector<vector<int>> (this->v, vector<int> (this->v,0));
        for(int i=0;i<e;i++) {
            int u,v,w;
            cin >> u >> v >> w;
            adj[u][v] = w;
        }
        return this->v;
    }

    

    bool bfs(int s, int t, vector<vector<int>>& residual, int *parent) {
        int visited[this->v] = {0};
        parent[s] = -1;
        queue<int> q;
        visited[s] = 1;
        q.push(s);
        
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            for(int i=0;i<this->v;i++) {
                if(! visited[i] && residual[u][i] > 0) {
                    parent[i] = u;
                    if(i == t) 
                        return true;
                    q.push(i);
                    visited[i] = 1;
                }
            }
        }
        return false;
    }

    int fordMax(int s, int t) {
        vector<vector<int>> residual = adj;
        int parent[this->v];
        parent[s] = -1;
        int maxC = 0;
        int u;
        while( bfs(s,t,residual,parent) ) {
            int flow = INT_MAX;
            for(int i=t; i!=s; i=parent[i]) {
                u = parent[i];
                flow = min(flow,residual[u][i]);
            }
            for(int i=t; i!=s; i=parent[i]) {
                u = parent[i];
                residual[u][i] -= flow;
                residual[i][u] += flow;
            }
            maxC += flow;
        }
        return maxC;
    }
};



int main() {

    Graph ob;
    int t = ob.createGraph();
    cout << ob.fordMax(0,t-1) << endl;
    return 0;
}
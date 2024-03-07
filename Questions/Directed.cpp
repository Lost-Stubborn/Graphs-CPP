#include <bits/stdc++.h>
using namespace std;

class Graph {
    int n,m;
    vector<int> adj[100];
    public:
    Graph(int n, int m) {
        this->n = n;
        this->m = m;
    }

    void createGraph() {
        for(int i=1;i<=m;i++) {
            int u,v;
            cin >> u >> v;
            adj[u].push_back(v);
            // adj[v].push_back(u);
        }
    }

    void display() {
        for(int i=0; i<n; i++) {
            cout << i << " -> ";
            for(auto it : adj[i]) {
                cout << it << ",";
            }
            cout << endl;
        }
    }

    vector<int> bfs(int start) {
        vector<int> ans;
        int vis[n+1] = {0};
        vis[start] = 1;
        queue<int> q;
        q.push(start);

        while(!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto it : adj[node]) {
                if(!vis[it]) {
                    q.push(it);
                    vis[it] = 1;
                }
            }
        }
        return ans;
    }
};



int main() {
    int n,m;
    cout << "Enter n and m : " << endl;
    cin  >> n >> m;

    Graph ob(n,m);
    ob.createGraph();
    ob.display();

    vector<int> ans = ob.bfs(2);
    //BFS display
    for(auto it : ans) {
        cout << it << ",";
    }
    return 0;
}
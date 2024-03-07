#include <bits/stdc++.h>
using namespace std;

vector<int> bfs(vector<int> adj[], int n) {

    vector<int> ans;
    int vis[n+1] = {0};
    queue<int> q;
    vis[1] = 1;
    q.push(1);

    while (!q.empty()) {
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

    //breadth first search
    cout << "BFS Traversal" << endl;
    vector<int> ans = bfs(adj,n);
    for(auto i : ans) {
        cout << i << ", ";
    }
    
    return 0;
}
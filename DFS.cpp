#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> adj[], int vis[], vector<int> &ans) {
    vis[node] = 1;
    ans.push_back(node);
    //every children
    for(auto it : adj[node]){
        if(!vis[it]) {
            dfs(it,adj,vis,ans);
        }
    }
}

vector<int> dfsOfGraph(int V, vector<int> adj[]) {
    int vis[V+1] = {0};
    int start = 1;
    vector<int> ans;
    dfs(start,adj,vis,ans);
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

    //depth first search
    cout << "DFS Traversal" << endl;
    vector<int> ans = dfsOfGraph(n,adj);
    for(auto i : ans) {
        cout << i << ", ";
    }
    return 0;
}
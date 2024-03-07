#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> adj[], int vis[]) {
    vis[node] = 1;
    // ans.push_back(node);

    for(auto it : adj[node]) {
        if(!vis[it]) {
            dfs(it,adj,vis);
        }
    }
}

// vector<int> dfsOfGraph(vector<int> adj[], int n) {
//     vector<int> ans;
//     int vis[n+1] = {0};
//     int start = 1;
//     dfs(start,adj,vis,ans);
//     return ans;
// }

void display(vector<int> adj[], int n) {
    for(int i=1;i<=n;i++) {
        cout << i << " -> ";
        for(auto it : adj[i]){
            cout << it << ",";
        }
        cout << endl;
    }
}

int provinces(vector<int> adj[], int V) {
    int vis[V+1] = {0};
    int count = 0;
    for(int i=1; i<=V; i++) {
        if(vis[i] == 0) {
            count++;
            dfs(i,adj,vis);
        }
    }
    return count;
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

    int ans = provinces(adj,n);
    cout << ans << endl;

    return 0;
}
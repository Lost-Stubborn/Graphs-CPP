#include <bits/stdc++.h>
using namespace std;

class Graph {
    int v;
    vector<vector<int>> adj;
    public: 
    Graph() {

    }
    void createGraph() {
        int e;
        cout << "Enter No. of Vertices and Edges : " << endl;
        cin >> this->v >> e;
        adj = vector<vector<int>> (this->v, vector<int> (this->v, 0));
        cout << "Add Edges: " << endl;
        for(int i=1;i<=e;i++) {
            int u,v,w;
            cin >> u >> v >> w;
            adj[u][v] = w; 
        }
    }

    void display() {
        int n = adj.size();
        int m = adj[0].size();
        for(int i=0;i<n;i++) {
            cout << i << "-> ";
            for(int j=0;j<n;j++) {
                if(adj[i][j] != 0) {
                    cout << "{" << j << "," << adj[i][j] << "} ";
                }
            }
            cout << endl;
        }
    }
};


int main() {

    Graph ob;
    ob.createGraph();
    ob.display();
    return 0;
}
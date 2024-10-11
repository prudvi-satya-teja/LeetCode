class Solution {
public:
    void solve(vector<bool>& vis, vector<vector<int>>& edges, int src) {
        vis[src] = true;

        for(int i=0; i<edges[src].size(); i++) {
            int neigh = edges[src][i];
            if(!vis[neigh]) {
                solve(vis, edges, neigh);
            }
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<bool> vis(n, false);

        vector<vector<int>> graph(n);

        for(int i=0; i<edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        solve(vis, graph, source);
        return vis[destination];
        
    }
};
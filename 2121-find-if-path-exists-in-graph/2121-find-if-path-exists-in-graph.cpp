class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int src, int dest) {
        vector<bool> vis(n, false);

        vector<vector<int>> graph(n);

        for(int i=0; i<edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        queue<int> q;
        q.push(src);


        while(!q.empty()) {
            int curr = q.front();
            if(curr == dest) return true;
            q.pop();

            if(!vis[curr]) {
                vis[curr] = true;

                for(int i=0; i<graph[curr].size(); i++) {
                    int neigh = graph[curr][i];
                    if(!vis[neigh]) {
                        q.push(neigh);
                    }
                }

            }
        }

        return false;
        
    }
};
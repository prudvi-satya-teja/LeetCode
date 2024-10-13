class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<vector<int>> graph(n);
        for(int i=0; i<pre.size(); i++) {
            int u = pre[i][0];
            int v = pre[i][1];

            graph[u].push_back(v);
        }

        vector<int> indeg(n, 0);
        
        for(int i=0; i<n; i++) {
            
            for(auto neigh: graph[i]) {
                indeg[neigh]++;
            }

        }

        queue<int> q;
        for(int i=0; i<n; i++) {
            if(indeg[i] == 0) {
                q.push(i);
            }
        }

        int count = 0;
        while(!q.empty()) {
            int top = q.front();
            q.pop();

            for(auto neigh : graph[top]) {
                indeg[neigh]--;
                if(indeg[neigh] == 0) {
                    q.push(neigh);
                }
            }
            count++;
        }
        return count == n;
    }
};
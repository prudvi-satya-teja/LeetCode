class Solution {
public:
    vector<vector<int>> paths;
    void solve(vector<vector<int>>& graph, int src, int tar, vector<int>& v) {
        if(src == tar) {
            paths.push_back(v);
            return;
        }

        for(int i=0; i<graph[src].size(); i++) {
            int neigh = graph[src][i];
            v.push_back(neigh);
            solve(graph, neigh, tar, v);
            v.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> v;
        v.push_back(0);
        solve(graph, 0, graph.size()-1, v);
        return paths;
    }
};
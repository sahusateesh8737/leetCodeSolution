class Solution {
public:
        bool dfs(int node , vector<int>&color , vector<vector<int>>&adj) {
        // Visit all neighbors
        for (int neighbor : adj[node]) {
            if (color[neighbor] == -1) {
                // Color with opposite color
                color[neighbor] = 1 - color[node];
                if (!dfs(neighbor , color , adj)) {
                    return false;
                }
            } else if (color[neighbor] == color[node]) {
                // Same color - NOT bipartite
                return false;
            }
        }
        return true;
    }


    bool isBipartite(vector<vector<int>>& graph) {
        int n  = graph.size();
        vector<int> color(n , -1);
        for (int i = 0; i < n; i++) {
            if (color[i] == -1) {
                color[i] = 0;
                if (!dfs(i , color , graph)) {
                    return false;
                }
            }
        }
        return true;
    }
};
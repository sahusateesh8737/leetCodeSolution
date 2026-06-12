#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    int LOG;
    vector<vector<int>> up;
    vector<int> depth;
    
    // DFS to calculate depths and precompute the 2^0-th parent for binary lifting
    void dfs(int node, int parent, int d, const vector<vector<int>>& adj) {
        depth[node] = d;
        up[node][0] = parent;
        
        // Build the binary lifting table for the current node
        for (int i = 1; i < LOG; i++) {
            if (up[node][i - 1] != -1) {
                up[node][i] = up[up[node][i - 1]][i - 1];
            } else {
                up[node][i] = -1;
            }
        }
        
        // Traverse children
        for (int neighbor : adj[node]) {
            if (neighbor != parent) {
                dfs(neighbor, node, d + 1, adj);
            }
        }
    }
    
    // Binary Lifting to find the Lowest Common Ancestor (LCA)
    int getLCA(int u, int v) {
        // Ensure u is the deeper node
        if (depth[u] < depth[v]) {
            swap(u, v);
        }
        
        // Bring u to the exact same depth as v
        int diff = depth[u] - depth[v];
        for (int i = 0; i < LOG; i++) {
            if ((diff >> i) & 1) {
                u = up[u][i];
            }
        }
        
        if (u == v) return u;
        
        // Move both nodes up simultaneously to find the LCA
        for (int i = LOG - 1; i >= 0; i--) {
            if (up[u][i] != -1 && up[u][i] != up[v][i]) {
                u = up[u][i];
                v = up[v][i];
            }
        }
        
        return up[u][0];
    }

public:
    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int n = edges.size() + 1;
        
        // Calculate the maximum power of 2 needed for the tree height
        LOG = 0;
        while ((1 << LOG) <= n) {
            LOG++;
        }
        
        up.assign(n + 1, vector<int>(LOG, -1));
        depth.assign(n + 1, 0);
        
        // Build the adjacency list
        vector<vector<int>> adj(n + 1);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        // Start DFS from node 1 (root), with parent as -1 and depth 0
        dfs(1, -1, 0, adj);
        
        // Precompute powers of 2 modulo 10^9 + 7
        vector<long long> pow2(n + 1, 1);
        long long MOD = 1e9 + 7;
        for (int i = 1; i <= n; i++) {
            pow2[i] = (pow2[i - 1] * 2) % MOD;
        }
        
        // Answer each query
        vector<int> ans;
        ans.reserve(queries.size());
        
        for (const auto& q : queries) {
            int u = q[0];
            int v = q[1];
            
            // If the start and end nodes are the same, the path length is 0
            if (u == v) {
                ans.push_back(0);
                continue;
            }
            
            int lca = getLCA(u, v);
            int L = depth[u] + depth[v] - 2 * depth[lca]; // Distance (number of edges)
            
            if (L == 0) {
                ans.push_back(0);
            } else {
                ans.push_back(pow2[L - 1]);
            }
        }
        
        return ans;
    }
};
class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& state, vector<int>& ans) {
        if (state[node] == 1) return true;

        if (state[node] == 2) return false;
        state[node] = 1;
        for (auto it : adj[node]) {
            if (dfs(it, adj, state, ans)) return true;
        }
        state[node] = 2; 
        ans.push_back(node); 

        return false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);

        for (auto &p : prerequisites) {
            adj[p[1]].push_back(p[0]);
        }

        vector<int> state(numCourses, 0);
        vector<int> ans;

        
        for (int i = 0; i < numCourses; i++) {
            if (dfs(i, adj, state, ans)) {
                return {};
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
class Solution {
public:
    vector<int> ans;

    void dfs(int stpoint, int prepoint, unordered_map<int, vector<int>>& adjmp) {
        ans.push_back(stpoint);

        for (int &v : adjmp[stpoint]) {
            if (v != prepoint) {
                dfs(v, stpoint, adjmp);
            }
        }
    }

    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, vector<int>> adjmp;

        // build graph
        for (auto &p : adjacentPairs) {
            int x = p[0], y = p[1];
            adjmp[x].push_back(y);
            adjmp[y].push_back(x);
        }

        // find starting point (degree = 1)
        int stpoint = -1;
        for (auto &it : adjmp) {
            if (it.second.size() == 1) {
                stpoint = it.first;
                break;
            }
        }

        // DFS traversal
        dfs(stpoint, INT_MIN, adjmp);

        return ans;
    }
};
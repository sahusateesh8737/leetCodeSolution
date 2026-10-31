class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        const int MOD = 1e9 + 7;

        // right[i][j] = paths exiting (i, j) to the right
        // down[i][j]  = paths exiting (i, j) downward
        vector<vector<int>> right(m, vector<int>(n, 0));
        vector<vector<int>> down(m, vector<int>(n, 0));

        // Starting cell (0, 0) is always 0
        right[0][0] = 1;
        down[0][0] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) continue;

                long long in_right = (j > 0) ? right[i][j - 1] : 0;
                long long in_down  = (i > 0) ? down[i - 1][j] : 0;

                if (grid[i][j] == 0) {
                    int total = (in_right + in_down) % MOD;
                    right[i][j] = total;
                    down[i][j] = total;
                } else {
                    // Mirror reflects right-moving into down, and down-moving into right
                    down[i][j] = in_right;
                    right[i][j] = in_down;
                }
            }
        }

        // Since grid[m - 1][n - 1] == 0, right[m - 1][n - 1] holds (in_right + in_down) % MOD
        return right[m - 1][n - 1];
    }
};

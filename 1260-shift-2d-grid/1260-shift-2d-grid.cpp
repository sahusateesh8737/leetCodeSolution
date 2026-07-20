#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int total = m * n;
        
     
        k = k % total;
        
        vector<vector<int>> ans(m, vector<int>(n));
        
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
           
                int new_idx = (r * n + c + k) % total;
                
                ans[new_idx / n][new_idx % n] = grid[r][c];
            }
        }
        
        return ans;
    }
};
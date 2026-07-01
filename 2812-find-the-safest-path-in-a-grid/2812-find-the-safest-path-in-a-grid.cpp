class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
 
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) {
            return 0;
        }

       
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        vector<vector<int>> dist(n, vector<int>(n, -1));
        queue<pair<int, int>> q;

       
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                    dist[i][j] = 0;
                }
            }
        }

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                
           
                if (nr >= 0 && nr < n && nc >= 0 && nc < n && dist[nr][nc] == -1) {
                    dist[nr][nc] = dist[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }
        priority_queue<pair<int, pair<int, int>>> maxHeap;
        vector<vector<bool>> visited(n, vector<bool>(n, false));

        maxHeap.push({dist[0][0], {0, 0}});
        visited[0][0] = true;

        while (!maxHeap.empty()) {
            auto [safe, pos] = maxHeap.top();
            maxHeap.pop();
            int r = pos.first;
            int c = pos.second;

           
            if (r == n - 1 && c == n - 1) {
                return safe;
            }

       
            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nr < n && nc >= 0 && nc < n && !visited[nr][nc]) {
                    visited[nr][nc] = true;
                  
                    int new_safe = min(safe, dist[nr][nc]);
                    maxHeap.push({new_safe, {nr, nc}});
                }
            }
        }

        return 0; 
    }
};
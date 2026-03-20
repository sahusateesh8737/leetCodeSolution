class Solution {
public:
    
    void bfs(int i, int j, vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        queue<pair<int,int>> q;
        q.push({i, j});
        grid[i][j] = '0'; // mark visited
        
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};
        
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            
            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];
                
                if (nx >= 0 && ny >= 0 && nx < m && ny < n 
                    && grid[nx][ny] == '1') {
                    
                    q.push({nx, ny});
                    grid[nx][ny] = '0'; // mark visited
                }
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                
                if (grid[i][j] == '1') {
                    count++;
                    bfs(i, j, grid); // call BFS function
                }
            }
        }
        
        return count;
    }
};
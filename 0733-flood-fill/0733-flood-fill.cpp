class Solution {
public:
    void bfs(int sr, int sc, vector<vector<int>>& ans, int ncolor, int pcolor) {
        int n = ans.size();
        int m = ans[0].size();
        queue<pair<int, int>> q;

        q.push({sr, sc});
        ans[sr][sc] = ncolor;

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx >= 0 && nx < n && ny >= 0 && ny < m && ans[nx][ny] == pcolor) {
                    ans[nx][ny] = ncolor; // Color it before pushing to prevent duplicate entries
                    q.push({nx, ny});
                }
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int inColor = image[sr][sc];
        vector<vector<int>>&ans = image;
    
        if (inColor == color) return image;

      
        bfs(sr, sc, ans, color, inColor);
        
        return image;
    }
};
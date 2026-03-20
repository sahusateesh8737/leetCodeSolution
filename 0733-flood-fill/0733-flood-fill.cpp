class Solution {
public:
    void dfs(int sr , int sc , vector<vector<int>>&ans , int newcolor , int dx[] , int dy[] , int sourceColor){
        ans[sr][sc] = newcolor;
        int n = ans.size();
        int m = ans[0].size();

        for(int i =0;i<4;i++){
            int newX = sr+ dx[i];
            int newY = sc + dy[i];
            if(newX >=0 && newX <n &&newY >=0 && newY <m  && ans[newX][newY] == sourceColor)
            dfs(newX , newY , ans , newcolor ,dx , dy ,sourceColor );
        }
}

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int sourceColor = image[sr][sc];
        vector<vector<int>>ans = image;
        if (sourceColor == color) {
            return image; 
        }

        int dx[] = {1 , -1 ,0 ,0};
        int dy[] = {0 ,0 ,-1 ,1};

        dfs(sr , sc , ans , color, dx , dy , sourceColor);
        return ans;
    }
};
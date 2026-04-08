class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    int negativeCount=0;

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j] <0){
                negativeCount++;
            }
        }
    }
    return negativeCount;
    }
};
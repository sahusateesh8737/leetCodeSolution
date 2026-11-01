class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if(n <= 2 ) return n;
        int max_pts = 2;
        for(int i = 0;i < n ;i++){
            unordered_map<double , int > slope_count; 
            for(int j = i + 1 ; j < n ;j++){
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];
                double slope = (dx == 0) ? numeric_limits<double>:: infinity():(double)dy / dx;
                slope_count[slope]++;
                
                // +1 accounts for the starting point points[i] itself
                max_pts = std::max(max_pts, slope_count[slope] + 1);
            }
        }
        return max_pts;
    }
};
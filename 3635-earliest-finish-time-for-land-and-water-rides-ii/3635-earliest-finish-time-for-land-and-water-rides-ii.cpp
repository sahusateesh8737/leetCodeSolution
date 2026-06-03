class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size();
        int m = waterStartTime.size();
        
       
        int minLandFinish = INT_MAX;
        for (int i = 0; i < n; ++i) {
            minLandFinish = std::min(minLandFinish, landStartTime[i] + landDuration[i]);
        }
        
        int minWaterFinish = INT_MAX;
        for (int j = 0; j < m; ++j) {
            minWaterFinish = std::min(minWaterFinish, waterStartTime[j] + waterDuration[j]);
        }
        
        int ans = INT_MAX;
        
        for (int j = 0; j < m; ++j) {
            int currentFinish = std::max(minLandFinish, waterStartTime[j]) + waterDuration[j];
            ans = std::min(ans, currentFinish);
        }
        
        for (int i = 0; i < n; ++i) {
            int currentFinish = std::max(minWaterFinish, landStartTime[i]) + landDuration[i];
            ans = std::min(ans, currentFinish);
        }
        
        return ans;
    }
};
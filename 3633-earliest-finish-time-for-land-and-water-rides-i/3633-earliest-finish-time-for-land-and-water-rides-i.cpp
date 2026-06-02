class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size();
        int m = waterStartTime.size();
        int minFinishTime = INT_MAX;

        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                
            
                int landFinish = landStartTime[i] + landDuration[i];
                int waterStart = max(landFinish, waterStartTime[j]);
                int totalTime1 = waterStart + waterDuration[j];
                
                int waterFinish = waterStartTime[j] + waterDuration[j];
                int landStart = max(waterFinish, landStartTime[i]);
                int totalTime2 = landStart + landDuration[i];
                
            
                minFinishTime = min({minFinishTime, totalTime1, totalTime2});
            }
        }

        return minFinishTime;
    }
};
class Solution {
public:
    int earliestTime(vector<vector<int>>& tasks) {
        int n = tasks.size();
        int m  = tasks[0].size();
        int minTime = INT_MAX;
        for(int i = 0;i<n;i++){
           
                int sum  = tasks[i][0] +tasks[i][1];
                minTime = min(minTime , sum);
      
        }
        return minTime;
    }
};
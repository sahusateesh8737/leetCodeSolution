class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<int>ans;
        for(int i = 0;i<n;i++){
            int endInterval = intervals[i][1];
            int minStartIndex = -1;
            long long minimumVal = 2e6;
            for(int j=0;j<n;j++){
                if(intervals[j][0] >= endInterval){
                    if(intervals[j][0] < minimumVal){
                        minimumVal = intervals[j][0];
                        minStartIndex = j;
                    }
                }
            }
            ans.push_back(minStartIndex);

        }
        return ans;
    }

};
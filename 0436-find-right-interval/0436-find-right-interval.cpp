class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<int>ans(n , -1);
        vector<pair<int ,int>>starts;
        for(int i=0;i<n;i++ ){
            starts.push_back({intervals[i][0] , i});
        }
        sort(starts.begin() , starts.end());

        for (int i = 0; i < n; i++) {
            int endVal = intervals[i][1];
            
      
            auto it = lower_bound(starts.begin(), starts.end(), make_pair(endVal, -2147483648));
            
            if (it != starts.end()) {
                ans[i] = it->second;
            }
        }
        
        return ans;
    }
};
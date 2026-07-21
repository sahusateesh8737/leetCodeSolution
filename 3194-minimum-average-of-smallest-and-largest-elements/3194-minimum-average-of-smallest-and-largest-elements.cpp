class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        int l = 0;
        int r = nums.size()-1;
        sort(nums.begin() , nums.end());
        double minAvg = INT_MAX;
        while(l < r){
            double sum = nums[l] + nums[r];
            double avg = sum / 2;
            minAvg = min(minAvg , avg);
            l++;
            r--;
        }
        return minAvg;
    }
};
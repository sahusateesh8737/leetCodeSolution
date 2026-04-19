class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0) {
            return -1;
        }
        vector<int> maxprefix(nums.size());
        maxprefix[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            maxprefix[i] = max(maxprefix[i - 1], nums[i]);
        }
        vector<int> minsuffix(nums.size());
        minsuffix[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            minsuffix[i] = min(minsuffix[i+1] , nums[i]);
        }
        for(int i=0;i<n;i++){
            int score = maxprefix[i] - minsuffix[i];
            if(score <= k){
                return i;
            }
        }
        return -1;
    }
};
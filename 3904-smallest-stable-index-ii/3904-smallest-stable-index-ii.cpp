class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0) return -1;
        
        // Precompute the suffix minimums
        vector<int> minsuffix(n);
        minsuffix[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            minsuffix[i] = min(minsuffix[i + 1], nums[i]);
        }
        
        // Calculate prefix maximum on the fly and find the first stable index
        int currentMax = nums[0];
        for (int i = 0; i < n; i++) {
            currentMax = max(currentMax, nums[i]);
            int score = currentMax - minsuffix[i];
            
            if (score <= k) {
                return i;
            }
        }
        
        return -1;
    }
};

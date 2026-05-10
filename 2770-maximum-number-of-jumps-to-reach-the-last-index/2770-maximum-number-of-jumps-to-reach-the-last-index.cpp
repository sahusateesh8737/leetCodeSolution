class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        
        // Initialize dp array with -1 (unreachable)
        std::vector<int> dp(n, -1);
        dp[0] = 0; // Starting position requires 0 jumps
        
        for (int i = 0; i < n; ++i) {
            // If the current index is unreachable, skip it
            if (dp[i] == -1) {
                continue;
            }
            
            // Check all possible future indices j
            for (int j = i + 1; j < n; ++j) {
                if (std::abs(nums[j] - nums[i]) <= target) {
                    // Update dp[j] with the max jumps to get there
                    dp[j] = std::max(dp[j], dp[i] + 1);
                }
            }
        }
        
        return dp[n - 1];
    }
};
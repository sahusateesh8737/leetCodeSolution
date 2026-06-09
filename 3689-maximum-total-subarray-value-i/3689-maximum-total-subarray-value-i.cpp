class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
         int max_val = *std::max_element(nums.begin(), nums.end());
        int min_val = *std::min_element(nums.begin(), nums.end());
        long long max_single_subarray_value = max_val - min_val;
        return max_single_subarray_value * k;
    }
};
class Solution {
public:
    bool canSortArray(vector<int>& nums) {
         vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());
        
        int n = nums.size();
        int i = 0;
        
        while (i < n) {
            int j = i;
            
            // Count set bits of current element
            int bitCount = __builtin_popcount(nums[i]);
            
            // Find segment of same set bits
            while (j < n && __builtin_popcount(nums[j]) == bitCount) {
                j++;
            }
            
            // Sort this segment
            sort(nums.begin() + i, nums.begin() + j);
            
            i = j;
        }
        
        return nums == sorted;
    }
};
class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        int mid_val = nums[nums.size() / 2];
        
        
        int counter = count(nums.begin(), nums.end(), mid_val);
        
       
        return counter == 1;
    }
};
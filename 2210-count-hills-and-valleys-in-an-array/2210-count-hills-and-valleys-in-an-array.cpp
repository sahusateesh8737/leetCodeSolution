class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n = nums.size();
        int leftValue = nums[0];
        int totalCount = 0;
        for(int i = 1 ;i<n-1;i++){
            if(leftValue < nums[i] && nums[i] > nums[i+1]){
                totalCount++;
                leftValue = nums[i];
            }
            else if(nums[i] < leftValue  && nums[i] < nums[i+1]){
                totalCount++;
                leftValue= nums[i];
            }
            
        }
        return totalCount;
    }
};
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = nums.size();
        int i=0;
        int j = 0;
        while(i<n){
            if(nums[i] %2== 0){
                swap(nums[j] , nums[i]);
                j++;
            }
            i++;
        }
        return nums;
    }
};
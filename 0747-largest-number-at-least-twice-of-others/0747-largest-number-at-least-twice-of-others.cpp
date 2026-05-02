class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int max= INT_MIN;
        int idx = -1;
        for(int i =0;i<nums.size();i++){
            if(nums[i] > max){
                max = nums[i];
                idx = i;
            }
        }

        for(int i =0;i<nums.size();i++){
            if(idx != i && nums[i] * 2 > max){
                return -1;
            }
        }
        return idx;
    }
};
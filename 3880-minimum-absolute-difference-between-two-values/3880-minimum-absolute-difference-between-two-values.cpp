class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums) {
        int last1  = -1;
        int last2 = -1;
        int minDis = 1e9;
        for(int i =0;i<nums.size();i++){
            if(nums[i] == 1){
                last1 = i;
                if(last2 != -1){
                    minDis = min(minDis ,abs(last1 - last2));
                }
            }
            else if(nums[i] ==2){
                last2 = i;
                if(last1 != -1){
                    minDis =  min(minDis ,abs(last1 - last2));
                }
            }
        }
        if(minDis==1e9){
            return -1;
        }
        return minDis;
    }
};
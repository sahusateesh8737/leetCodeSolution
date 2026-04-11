class Solution {
public:
    int jump(vector<int>& nums) {
        int jump = 0;
        int currentFarthest = 0;
        int currentEnd=0;
        for(int i =0;i<nums.size()-1;i++){
            currentFarthest  = max(currentFarthest  , i + nums[i]);
            if(i == currentEnd){
                jump++;
                currentEnd = currentFarthest;
            }
        }
        return jump;
    }
};
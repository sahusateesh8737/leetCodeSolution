class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n = nums.size();
        bool monoIncre= false;
        bool monoDecre= false;
        for(int i = 0;i<n-1;i++){
            if(nums[i] < nums[i+1]){
                monoIncre= true;
            }
            if(nums[i] > nums[i+1]){
                monoDecre= true;
            }

        }
        if(monoIncre== true && monoDecre== true){
            return false;
        }
        return true;
    }
};
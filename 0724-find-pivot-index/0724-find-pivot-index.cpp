class Solution {
public:
    int leftsum(int l , vector<int>&nums){
            int lsum =0;
            for(int i=0;i<l;i++){
                lsum+=nums[i];
            }
            return lsum;
    }
    int rightsum(int r , vector<int>&nums){
        int rsum =0;
        for(int i= r;i<nums.size();i++){
            rsum +=nums[i];
        }
        return rsum;

    }
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        
        for(int i = 0 ; i<n;i++){
            int left = leftsum(i,nums);
            int right = rightsum(i+1 , nums);
            if(left == right){
                return i;
            }

        }
        return -1;
    }
};
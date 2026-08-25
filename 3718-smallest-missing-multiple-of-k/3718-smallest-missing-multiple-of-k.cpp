class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        set<int>st;
        for(int i =0;i<nums.size();i++){
            st.insert(nums[i]);
        }
        for(int i = 1;i<=nums.size()*k+1;i++){
            if(!st.contains(i * k)){
                return (i*k);
            }
        }
        return -1;
    }
};
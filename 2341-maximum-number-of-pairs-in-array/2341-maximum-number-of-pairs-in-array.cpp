class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {

        sort(nums.begin() , nums.end());
        int n = nums.size();
        int pair =0;
        int leftOver =0;
        int i=0;
        while(i<n){
            if(i+1 <n && nums[i]==nums[i+1]){
                pair++;
                i+=2;
            }
            else{
                leftOver++;
                i+=1;
            }
        }
        
        return {pair , leftOver};
    }
};
class Solution {
public:
    int minMergedInteger(vector<int>& nums) {
        int min_val = INT_MAX ;
        for(int i =0;i< nums.size() ; i+= 2){
            int a = nums[i];
            int b = nums[i + 1];
            int multi = 1 ;
            while(multi <= b){
                multi *= 10;
            }
            int merged = a * multi + b;
            min_val = min(min_val , merged);
        }
        return min_val;
    }
};
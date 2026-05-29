class Solution {
public:
    int sumCal(int n){
        int sum = 0 ;
    while(n > 0){
        int remainder = n % 10 ;
        sum += remainder ;
        n = n / 10 ;
    }
    return sum;
    }
    int minElement(vector<int>& nums) {
        for(int i =0;i<nums.size();i++){
         int digit = sumCal(nums[i]);
         nums[i] = digit;
        }

        int min_vec = *min_element(nums.begin(), nums.end());
    return min_vec;
    }
     
};
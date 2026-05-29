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
        int mini=36;
        for(int i =0;i<nums.size();i++){
         int digit = sumCal(nums[i]);
             mini = min(mini , digit);
        }

       return mini;
    }
     
};
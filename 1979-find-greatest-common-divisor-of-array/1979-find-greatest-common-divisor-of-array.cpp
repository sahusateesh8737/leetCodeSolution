class Solution {
public:
    int findGCD(vector<int>& nums) {
        int a =*min_element(nums.begin() , nums.end());
        int b =*max_element(nums.begin() , nums.end());
        
        while(a!=0){
            int rem = b%a;
            b=a;
            a= rem;

        }
        return b;
    }
};
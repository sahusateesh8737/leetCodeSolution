class Solution {
public:
    int memo[105];
    int solve(vector<int>&nums , int i , int end){
        if(i > end) {
             return 0;
        }
        if(memo[i] != -1){
            return memo[i];
        }
        int loot = nums[i] + solve(nums , i + 2 , end);
        int skip= solve(nums , i + 1 , end);
        return memo[i] = max(loot , skip);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n ==1 ){
            return nums[0];
        }
        // case 1 from 0 to n-2;
        memset(memo , -1 , sizeof(memo));
        int case1 = solve(nums , 0 , n-2);
        // case 2 from 1 to n-1;
        memset(memo , -1 , sizeof(memo));
        int case2 = solve(nums , 1 , n-1);
        return max(case1 , case2 );
    }
};
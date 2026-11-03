class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int moves = 0;
        int maxim = *std::max_element(nums.begin() , nums.end());
        if(nums.empty()){
            return 0;
        }
        for(int i =0;i<n;i++)
        {
            int diff = maxim-nums[i];
            if(diff>=0){
                nums[i] = nums[i] + diff;
                moves = moves + diff;
            }
        }
        return moves;
    }
};
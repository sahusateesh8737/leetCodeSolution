class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        int max_lent = 0;
        for(int i = 0;i<n ;i++){
            unordered_set<int>st;
            int even = 0;
            int odd = 0 ;
            for(int j =i;j<n;j++){
                if(!st.contains(nums[j])){
                    st.insert(nums[j]);
                    if(nums[j] %2 == 0){
                        even++;
                    }
                    else {
                        odd++;
                    }
                }
                if(even == odd){
                    max_lent = max(max_lent , j-i+1);
                }
            }
        }
        return max_lent;
    }
};
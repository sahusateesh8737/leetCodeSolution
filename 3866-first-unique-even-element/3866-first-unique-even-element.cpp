class Solution {
public:
    int firstUniqueEven(vector<int>& nums) {
        map<int,int>mp;
        for(int it :nums){
            mp[it]++;
        }
        for(auto it : nums){
            if(it %2 ==0 && mp[it] == 1){
                return it;
            }
        }
        return -1;
    }
};
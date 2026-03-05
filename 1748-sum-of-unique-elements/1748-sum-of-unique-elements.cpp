class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        map<int , int>mp;
        for(int it : nums){
            mp[it]++;
        }
        int sum = 0;
        for(auto it : mp){
            if(it.second == 1){
                sum = sum + it.first;
            }
        }
        return sum;
    }
};
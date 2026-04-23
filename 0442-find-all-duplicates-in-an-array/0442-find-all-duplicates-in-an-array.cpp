class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int , int>freq;
        vector<int>ans;
        for(int n : nums){
            freq[n]++;
        }
    for(auto it : freq){
        if(it.second == 2){
            ans.push_back(it.first);
        }
    }
    return ans;
    }
};
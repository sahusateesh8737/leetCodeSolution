class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int ,int>mp;
        for(int i=0;i<=nums.size()-k ;i++){
            set<int>st;
            for(int j = i ; j<i + k;j++){
                st.insert(nums[j]);
            }
            for(int x: st){
                mp[x]++;
            }
        }
        int ans = -1;
        for(auto it : mp){
            if(it.second == 1){
                ans = max(ans , it.first);
            }
        }
        return ans;
    }
};
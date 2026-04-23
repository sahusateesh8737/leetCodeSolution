class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
       int n= nums.size();
        vector<int>ans(n+1,0);
        vector<int>a;
        
        for(int it:nums){
            ans[it]++;
        }
        for(int i=0;i<=n;i++){
            if(ans[i] ==2){
                a.push_back(i);
            }
        }
        return a;
    }
};
class Solution {
public:
void combi(vector<int>&candi, int ind , int sum , vector<int>&lis , vector<vector<int>>&ans){
            if (sum == 0){
                ans.push_back(lis);
                return;
            }
            if(sum < 0){
                return ;
            }
            if(ind < 0){
                return;
            }

            combi(candi , ind -1 , sum , lis , ans);
            lis.push_back(candi[ind]);
            combi(candi, ind , sum - candi[ind] , lis , ans);
            lis.pop_back();
        }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>lis ;
        combi(candidates , candidates.size() -1  , target , lis  ,ans);
        return ans;
    }
};
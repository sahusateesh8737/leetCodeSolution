class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>>result;
        unordered_map<int  ,vector<int>>group;
        for(int i =0;i<groupSizes.size();i++){
            int groupsize = groupSizes[i];
            group[groupsize].push_back(i);
            if(group[groupsize].size()== groupsize){
                result.push_back(group[groupsize]);
                 group[groupsize].clear();
            }

        }
        return result;
    }
};
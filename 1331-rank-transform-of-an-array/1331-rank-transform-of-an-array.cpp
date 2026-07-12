class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int>sortedArr = arr;
        sort(sortedArr.begin() , sortedArr.end());
        unordered_map<int , int>mp;
        int count = 1;
        for(int num : sortedArr){
            if(mp.find(num) == mp.end()){
                mp[num] = count++;
            }
        }
        vector<int >ans;
        for(auto it : arr){
            ans.push_back(mp[it]);
        }
        return ans;
    }
};
class Solution {
public:
    int findLucky(vector<int>& arr) {
        map<int ,int>mp;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]++;
        }
        for(auto it = mp.rbegin(); it != mp.rend(); ++it){
            if(it->first==it->second){
                return it->first;
            }
        }
        return -1;
    }
};
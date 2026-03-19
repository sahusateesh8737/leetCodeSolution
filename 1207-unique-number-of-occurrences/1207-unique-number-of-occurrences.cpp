class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int , int>mp;
        unordered_set<int>st;
        for(int i =0;i<arr.size();i++){
                mp[arr[i]]++;
        }
        for(auto it : mp){
            int num = it.second;
            if(st.find(num) !=st.end()){
                return false;
            }
            st.insert(num);
        }
        return true;
    }
};
class Solution {
public:
    bool areOccurrencesEqual(string s) {
        map<int ,int> mp;
        for(char c : s){
            mp[c]++;
        }
        set<int>st;
        for(auto it : mp){
            st.insert(it.second);
        }
        return (st.size()==1);
    }
};
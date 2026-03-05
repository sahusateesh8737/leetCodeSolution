class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        for(char it : s){
            freq[it]++;
        }
        priority_queue<pair<int, char>> pq;
        for (auto& entry : freq) {
            pq.push({entry.second, entry.first});
        }
        string ans = "";
        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            ans.append(top.first, top.second);
        }
        return ans;
    }

};
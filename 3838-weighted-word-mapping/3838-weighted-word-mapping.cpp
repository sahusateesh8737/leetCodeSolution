class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string result = "";
        
        for (const string& word : words) {
            int current_weight = 0;
            for (char c : word) {
                current_weight += weights[c - 'a'];
            }
            
            int mod_val = current_weight % 26;
            result += (char)('z' - mod_val);
        }
        
        return result;
    }
};
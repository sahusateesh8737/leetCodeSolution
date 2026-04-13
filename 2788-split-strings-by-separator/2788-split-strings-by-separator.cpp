class Solution {
public:
    vector<string> splitWordsBySeparator(vector<string>& words, char separator) {
        vector<string> ans;
      for (const string& word : words) {
            stringstream ss(word);
            string part;
            while (getline(ss, part, separator)) {
                if (!part.empty()) {
                    ans.push_back(part);
                }
            }
        }
        
        return ans;

    }
};
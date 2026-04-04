#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    string sortString(std::string s) {

        vector<int> count(26, 0);
        for (char c : s) {
            count[c - 'a']++;
        }
        
        string result = "";
        int n = s.length();

        while (result.length() < n) {
           
            for (int i = 0; i < 26; i++) {
                if (count[i] > 0) {
                    result += (i + 'a');
                    count[i]--;
                }
            }
            
           
            for (int i = 25; i >= 0; i--) {
                if (count[i] > 0) {
                    result += (i + 'a');
                    count[i]--;
                }
            }
        }
        
        return result;
    }
};
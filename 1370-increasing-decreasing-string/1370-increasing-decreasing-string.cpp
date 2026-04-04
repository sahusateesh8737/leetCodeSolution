#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    std::string sortString(std::string s) {
        // Create a frequency array for the 26 lowercase English letters
        std::vector<int> count(26, 0);
        for (char c : s) {
            count[c - 'a']++;
        }
        
        std::string result = "";
        int n = s.length();
        
        // Loop until we have processed all characters
        while (result.length() < n) {
            // Forward pass: Append from 'a' to 'z'
            for (int i = 0; i < 26; i++) {
                if (count[i] > 0) {
                    result += (i + 'a');
                    count[i]--;
                }
            }
            
            // Backward pass: Append from 'z' to 'a'
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
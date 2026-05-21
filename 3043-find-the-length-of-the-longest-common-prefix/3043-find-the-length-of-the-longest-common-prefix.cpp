#include <vector>
#include <unordered_set>
#include <string>
#include <algorithm>

class Solution {
public:
    int longestCommonPrefix(std::vector<int>& arr1, std::vector<int>& arr2) {
        std::unordered_set<int> prefixes;

        for (int num : arr1) {
            while (num > 0) {
                prefixes.insert(num);
                num /= 10; 
            }
        }
        
        int maxLength = 0;
        
 
        for (int num : arr2) {
            while (num > 0) {
              
                if (prefixes.find(num) != prefixes.end()) {
               
                    int currentLength = std::to_string(num).length();
                    maxLength = std::max(maxLength, currentLength);
                    break; 
                }
                num /= 10;
            }
        }
        
        return maxLength;
    }
};
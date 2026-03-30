class Solution {
public:
    int firstMatchingIndex(string s) {
        int low = 0 ;
        int high = s.length()-1;
        while(low<=high){
            if(s[low] == s[high]){
                return low;
            }
            low++;
            high--;
        }
        return -1;
    }
};
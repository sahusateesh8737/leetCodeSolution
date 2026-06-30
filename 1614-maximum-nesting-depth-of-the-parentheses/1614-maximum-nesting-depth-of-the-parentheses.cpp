class Solution {
public:
    int maxDepth(string s) {
        int  n = s.length();
        int count = 0;
        int current = 0;
        for(int i = 0;i<n ; i++){
            if(s[i] == '(') {
                current++;
                count = max(count , current);
            }
            else if (s[i] == ')') {
                 current--;
            }
        }
        return count;
    }
};
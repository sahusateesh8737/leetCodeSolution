class Solution {
public:
    int minimumDeletions(string s) {
        int deletion = 0;
        int bcount = 0;
        for (auto c : s) {
            if (c == 'b') {
                bcount++;
            } else {
                deletion = min(deletion + 1, bcount);
            }
        }
        return deletion;
    }
};
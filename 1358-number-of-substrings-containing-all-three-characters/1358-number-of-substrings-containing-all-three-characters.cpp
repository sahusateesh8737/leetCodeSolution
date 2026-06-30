class Solution {
public:
    int numberOfSubstrings(string s) {
        int l1 = -1 , l2 = -1 , l3 = -1;
        int count =0;
        for(int i =0;i<s.length() ; i++){
           if (s[i] == 'a') l1 = i;
            else if (s[i] == 'b') l2 = i;
            else if (s[i] == 'c') l3 = i;

            if (l1 != -1 && l2 != -1 && l3 != -1) {
                count += min({l1, l2, l3}) + 1;
            }
        }
        return count;
    }
};
class Solution {
public:
    string reverseByType(string s) {
        vector<char> letters, specials;
        for(char c : s){
            if(c >= 'a' && c <= 'z') letters.push_back(c);
            else specials.push_back(c);
        }
        
        reverse(letters.begin(), letters.end());
        reverse(specials.begin(), specials.end());
        
        int i = 0, j = 0;
        for(int k = 0; k < s.size(); k++){
            if(s[k] >= 'a' && s[k] <= 'z'){
                s[k] = letters[i++];
            } else {
                s[k] = specials[j++];
            }
        }
        
        return s;
    }
};

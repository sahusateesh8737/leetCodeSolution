class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int>last(26,-1);
        vector<int>first(26,-1);
        for(int i = 0;i<word.length();i++){
            char ch = word[i];
            if(ch >='a' && ch <='z'){
                last[ch - 'a'] = i;
            }
            else if(ch >='A' && ch <= 'Z'){
                if(first[ch - 'A'] == -1){
                    first[ch -'A'] = i;
                }
            }
        }
        int count = 0;
        for(int i = 0;i<26;i++){
            if(last[i] != -1 && first[i] != -1 && last[i] < first[i]){
                count++;
            }
        }
        return count;
    }
};
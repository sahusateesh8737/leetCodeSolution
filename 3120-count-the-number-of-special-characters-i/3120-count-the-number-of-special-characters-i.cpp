class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_set<char>lowerChar;
        unordered_set<char>upperChar;
        for(char ch : word){
            if(ch >= 'a' && ch <='z'){
                lowerChar.insert(ch);
            }
             if(ch >= 'A' && ch <='Z'){
                upperChar.insert(ch);
            }
        }
        int specialcount = 0;
        for(char ch = 'a' ; ch <='z' ;ch++){
            char upper = ch -32;
            if(lowerChar.count(ch) && upperChar.count(upper)){
                specialcount++;
            }
        }
        return specialcount;
    }
};
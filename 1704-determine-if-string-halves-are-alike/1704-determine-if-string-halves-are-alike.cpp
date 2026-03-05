class Solution {
public:
    bool halvesAreAlike(string s) {
        int firstHalf = 0;
        int secondHalf = 0;
        int half = s.length()/2;
        for(int  i =0;i<half;i++){
            if(s[i]== 'a' || s[i] == 'A' || s[i]== 'e' || s[i] == 'E'||s[i]== 'i' || s[i] == 'I' ||s[i]== 'o' || s[i] == 'O'|| s[i]== 'u' || s[i] == 'U'){
                firstHalf++;
            }
        }
        for(int  i =half;i<s.length();i++){
            if(s[i]== 'a' || s[i] == 'A' || s[i]== 'e' || s[i] == 'E'||s[i]== 'i' || s[i] == 'I' ||s[i]== 'o' || s[i] == 'O'|| s[i]== 'u' || s[i] == 'U'){
            secondHalf++;
            }
        }
        if(firstHalf == secondHalf){
            return true;
        }
        return false;

    }
};
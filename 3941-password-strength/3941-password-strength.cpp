class Solution {
public:
    int passwordStrength(string password) {
        int sum = 0;
        unordered_set<char> uniqueChars;
    for(int i = 0;i< password.length();i++){
         char ch = password[i];
         if (uniqueChars.count(ch) == 0) {
                uniqueChars.insert(ch);
        if(ch >= 'a' && ch <= 'z'){
            sum = sum+1;
        }
        if(ch >= 'A' && ch <= 'Z'){
            sum = sum+2;
        }
        if(ch >= '0' && ch <= '9'){
            sum = sum+3;
        }
        if(ch == '!' || ch == '@' || ch == '#' || ch == '$'){
            sum = sum+5;
        }
         }
    }
    return sum;
    }
};
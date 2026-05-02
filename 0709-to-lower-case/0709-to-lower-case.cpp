 
class Solution {
public:
    string toLowerCase(string s) {
        string ans= "";
        
        for(char ch : s){
            char c =tolower(ch);
            ans = ans + c;
        }
        return ans;
    }
};
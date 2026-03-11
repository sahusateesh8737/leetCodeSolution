class Solution {
public:
    string trimTrailingVowels(string s) {
        string ans = "";
        bool flag = true;
        for(int i=s.length()-1;i>=0;i--){
            if((s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' )&& flag){
                continue;
            }
            else{
                flag = false;
                ans = ans + s[i];
            }
        }
        reverse(ans.begin() , ans.end());
        return ans;
    }
};
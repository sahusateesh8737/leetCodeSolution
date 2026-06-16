class Solution {
public:
    string processStr(string s) {
        int n = s.length();
        string st = "";
        for(int i =0;i<n;i++){
            if(s[i] >= 'a' && s[i] <= 'z'){
                st += s[i];
            }
            else if(s[i] == '%'){
                reverse(st.begin() , st.end());
            }
            else if(s[i] == '#'){
                st +=st;
            }
            else {
                if(!st.empty()){
                    st.pop_back();
                }
            }
        }
        return st;
    }
};
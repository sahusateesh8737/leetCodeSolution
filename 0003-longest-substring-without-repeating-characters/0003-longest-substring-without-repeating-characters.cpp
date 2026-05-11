class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int currLen = 0;
    int len = 0;
    int count =0;
    for(int i=0;i<s.length();i++){
        string ans  = "";
        for(int j =i;j<s.length();j++){
            if(ans.find(s[j]) == string ::npos){
                ans  = ans + s[j];
                // cout << ans << endl;
                int currLen = ans.length();
                if(currLen > len){
                    len = currLen;
                }
            }
            else{
                break;
            }
        }

    }
   
   return len;
    }
};
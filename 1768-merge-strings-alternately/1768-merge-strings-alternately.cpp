class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans = "";
        int n1 = word1.length();
        int n2 = word2.length();
        int i=0;
        while(i<n1 || i<n2){
            if(i<n1){
                ans += word1[i];
            }
            if(i<n2){
                ans+=word2[i];
            }
            i++;
        }
        return ans;
    }
};
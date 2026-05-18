class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string st1 = "";
        string st2= "";
        for(int i = 0;i<word1.size();i++){
            st1 = st1 + word1[i];
        }
        for(int i = 0;i< word2.size();i++){
            st2 = st2 + word2[i];
        }
        if(st1 == st2){
            return true;
        }
        return false;
    }
};
class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
    
        int total=0;
        for(auto sent : sentences){
            int spaces = count(sent.begin(), sent.end(), ' ');
            total = max(total , spaces);
        }
        return total+1;
    }
};
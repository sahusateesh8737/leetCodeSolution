class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        unordered_map<char , int>rowMap;
        string row1 = "qwertyuiop";
        string row2 = "asdfghjkl";
        string row3 = "zxcvbnm";

        for(char c : row1){
            rowMap[c] = 1;
        }
        for(char c : row2){
            rowMap[c] = 2;
        }
        for(char c : row3){
            rowMap[c] = 3;
        }
      
        vector<string> result;

        for(string word : words){
            if(word.empty()){
                continue;
            }
            // ab hum word ka pehla characcter ka number nikalenge ki keyboard ke kis number ki row me aayega
            int firstCharacterRow = rowMap[tolower(word[0])];
            bool isValid = true;
            for(char c : word) {
                if(rowMap[tolower(c)] != firstCharacterRow){
                    isValid = false;
                    break;
                }
            }
            if(isValid){
                result.push_back(word);
            }
        }
        return result;
    }
};
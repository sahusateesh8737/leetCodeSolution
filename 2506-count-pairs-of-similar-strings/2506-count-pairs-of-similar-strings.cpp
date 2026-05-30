class Solution {
public:
    int similarPairs(vector<string>& words) {
        int n = words.size();
        int count =0;
        vector<unordered_set<char>>wordSet(n);
        for(int i = 0;i<n;i++){
            for(char ch : words[i]){
                wordSet[i].insert(ch);
            }
        }

        for(int i =0;i<n;i++){
            for(int j =i+1;j<n;j++){
                if(wordSet[i] == wordSet[j]){
                    count++;
                }
            }
        }
        return count;
    }

};
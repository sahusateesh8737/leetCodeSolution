class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char>allowedSet(allowed.begin() , allowed.end());
        int count =0;
        for(auto word : words){
            bool consistent = true;
            for( auto ch : word){
                if(!allowedSet.contains(ch)){
                    consistent = false;
                    break;
                }

            }
            if(consistent){
                count++;
            }
        }
        return count;
    }
};
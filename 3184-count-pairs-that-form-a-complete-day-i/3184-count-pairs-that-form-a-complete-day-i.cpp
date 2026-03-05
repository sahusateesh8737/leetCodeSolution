class Solution {
public:
    int countCompleteDayPairs(vector<int>& hours) {
        map<int,int> mp;
        int count = 0;

        for(int h : hours){
            int rem = h % 24;
            int need = (24 - rem) % 24;

            if(mp.count(need)){
                count += mp[need];
            }

            mp[rem]++;
        }

        return count;
    }
};
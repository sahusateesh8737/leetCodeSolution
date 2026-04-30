class Solution {
public:
    int findComplement(int num) {
        int temp = num;
        unsigned int mask =0;

        while(temp > 0){
            temp = temp >>1;
            mask = (mask << 1 )|1;
        }
        return mask ^ num;
    }
};
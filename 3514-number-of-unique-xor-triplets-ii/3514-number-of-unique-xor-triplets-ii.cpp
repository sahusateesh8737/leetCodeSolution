class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        unordered_set<int> one, two, three;
        for (int x : nums)
            one.insert(x);
        for (int a : one)
            for (int b : nums)
                two.insert(a ^ b);
        for (int x : two)
            for (int y : nums)
                three.insert(x ^ y);
        return three.size();
    }
};
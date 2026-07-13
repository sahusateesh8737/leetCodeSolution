class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string digits = "123456789";
        vector<int>ans;

        int minimum = to_string(low).length();
        int maximum = to_string(high).length();
        for(int i = minimum ; i <= maximum ;i++){
            for(int j = 0; j <= 9-i ; j++){
                string sub = digits.substr(j , i);
                int num = stoi(sub);

                if(num >= low && num <= high){
                    ans.push_back(num);
                }
            }
        }
    return ans;
    }
};
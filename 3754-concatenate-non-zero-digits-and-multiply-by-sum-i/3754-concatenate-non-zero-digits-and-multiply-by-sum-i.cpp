class Solution {
public:
    long long sumAndMultiply(int n) {
         if (n == 0) {
            return 0;
        }
        string s = to_string(n);
    string ans = "";
    for(int i = 0 ; i < s.length() ; i++){
        if(s[i]!='0'){
            ans += s[i];
        }
    }
    if (ans.empty()) {
            return 0;
        }
    long long sum = 0;
    for(int i = 0 ; i < ans.length() ; i++){
        sum += (ans[i] - '0');
    }
    long long num = stoll(ans);
    return num * sum;
    }
};
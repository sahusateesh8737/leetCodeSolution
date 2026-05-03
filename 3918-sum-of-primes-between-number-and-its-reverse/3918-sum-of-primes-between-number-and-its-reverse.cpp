class Solution {
public:
    bool isPrime(int n) {

        if (n <= 1)
            return false;

        if (n == 2 || n == 3)
            return true;

        if (n % 2 == 0 || n % 3 == 0)
            return false;
        for (int i = 5; i * i <= n; i = i + 6)
            if (n % i == 0 || n % (i + 2) == 0)
                return false;

        return true;
    }

    int sumOfPrimesInRange(int num) {
        string s = to_string(num);
        reverse(s.begin(), s.end());
        int r = stoi(s);
        int mini = min(num, r);
        int maxi = max(num, r);

        int sum = 0;

        for (int i = mini; i <= maxi; i++) {
            if (isPrime(i)) {
                sum += i;
            }
        }
        return sum;
    }
};
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPossible(vector<int>& target) {
        long long sum = 0;
        priority_queue<long long> pq;

        for (int x : target) {
            sum += x;
            pq.push(x);
        }

        while (true) {
            long long maxVal = pq.top();
            pq.pop();

            long long restSum = sum - maxVal;

            // success cases
            if (maxVal == 1 || restSum == 1)
                return true;

            // impossible cases
            if (restSum == 0 || maxVal < restSum)
                return false;

            long long prev = maxVal % restSum;

            if (prev == 0)
                return false;

            pq.push(prev);
            sum = restSum + prev;
        }
    }
};
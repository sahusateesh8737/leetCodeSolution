class Solution {
public:
    int elevatorRequests(int n, vector<int>& requests) {
        int num = requests.size();
        int currentfloor = 0;
        int time  = 0;
        for(int i =0;i <num;i++){
            int floordiff = abs(requests[i] - currentfloor);
            currentfloor = requests[i];
            time = time + floordiff;
        }
        return time ;
    }
};
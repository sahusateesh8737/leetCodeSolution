class Solution {
public:
    int missingInteger(vector<int>& arr) {
        int sum = arr[0];
    
    for(int i =1;i < arr.size();i++){
        if(arr[i] == arr[i-1] +1 ){
            sum +=arr[i];
            
        }
        else {
        break;
        }
    }
    int num = sum;
    while (find(arr.begin() , arr.end() , num)!= arr.end()) {
            num++;
    }
    return num;
    }
};
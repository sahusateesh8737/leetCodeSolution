class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        // for checking arr boundary
        if(start < 0 || start >= arr.size()){
            return false;
        }
        // if index value is negative means we already come here 
        if(arr[start] < 0 ){
            return false;
        }
        // target found
        if(arr[start] == 0){
            return true;
        }
        // power of current index
        int jumpStep = arr[start];
        // mark visited 
        arr[start] = -1;
        return canReach(arr , start + jumpStep) || canReach(arr , start - jumpStep);

    }
};
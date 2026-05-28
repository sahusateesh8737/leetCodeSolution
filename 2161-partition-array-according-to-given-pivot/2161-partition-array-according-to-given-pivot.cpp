class Solution {
public:
    vector<int> pivotArray(vector<int>& arr, int pivot) {
      vector<int> lessThanPivot;
    vector<int> equalToPivot;     // Pivot ke barabar wale elements ke liye
    vector<int> greaterThanPivot;
    
    // Single pass mein teeno ko alag kar lo
    for(int i = 0; i < arr.size(); i++) {
        if(arr[i] < pivot) {
            lessThanPivot.push_back(arr[i]);
        }
        else if(arr[i] == pivot) {
            equalToPivot.push_back(arr[i]);
        }
        else {
            greaterThanPivot.push_back(arr[i]);
        }
    }
    
    // Teeno ko line se merge kar do
    vector<int> partitionedArray;
    
    for(int x : lessThanPivot) partitionedArray.push_back(x);
    for(int x : equalToPivot)  partitionedArray.push_back(x);
    for(int x : greaterThanPivot) partitionedArray.push_back(x);
     

        // Print the partitioned array
        return partitionedArray;
    }
};
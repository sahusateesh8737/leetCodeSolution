class RandomizedSet {
private: 
    vector<int>arr;
    unordered_map<int , int>mp;
public:

    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.find(val) != mp.end()){
            return false;
        }
        arr.push_back(val);
        mp[val] = arr.size() -1;
        return true;
    }
    
    bool remove(int val) {
        if(mp.find(val) == mp.end()){
            return false;
        }
        int indexToRemove = mp[val];
        // ab swap kar denge 
        swap(arr[indexToRemove] , arr.back());
        mp[arr[indexToRemove]] = indexToRemove;
        arr.pop_back();
        mp.erase(val);
        return true;

        
    }
    
    int getRandom() {
        int rnum = rand() %arr.size();
        return arr[rnum];
        
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
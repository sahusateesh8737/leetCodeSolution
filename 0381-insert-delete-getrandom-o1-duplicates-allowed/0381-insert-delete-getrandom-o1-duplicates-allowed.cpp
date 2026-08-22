class RandomizedCollection {
private:
    vector<int> arr;
    unordered_map<int, unordered_set<int>> mp; // value -> set of indices

public:
    RandomizedCollection() {}

    bool insert(int val) {
        bool alreadyExists = mp.find(val) != mp.end() && !mp[val].empty();

        arr.push_back(val);
        mp[val].insert(arr.size() - 1);

        return !alreadyExists; // true if this was a NEW value
    }

    bool remove(int val) {
        if (mp.find(val) == mp.end() || mp[val].empty()) {
            return false; // val exist hi nahi karta
        }

        int indexToRemove = *mp[val].begin(); // val ka koi bhi ek index utha lo
        int lastIndex = arr.size() - 1;
        int lastElement = arr[lastIndex];

        // swap: val ki jagah pe last element rakh do
        arr[indexToRemove] = lastElement;

        // index bookkeeping update karo
        mp[val].erase(indexToRemove);
        if (indexToRemove != lastIndex) {
            mp[lastElement].erase(lastIndex);
            mp[lastElement].insert(indexToRemove);
        }

        arr.pop_back();
        if (mp[val].empty()) {
            mp.erase(val); // agar ab val ka koi index bacha hi nahi, map se hata do
        }

        return true;
    }

    int getRandom() {
        int rnum = rand() % arr.size();
        return arr[rnum];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
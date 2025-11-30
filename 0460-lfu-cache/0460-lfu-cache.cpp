class LFUCache {
private:
    int capacity, minFreq;
    unordered_map<int, pair<int,int>> keyToValFreq; // key -> {value, freq}
    unordered_map<int, list<int>> freqToList;       // freq -> LRU list of keys
    unordered_map<int, list<int>::iterator> keyToIter; // key -> iterator in list

    void updateFreq(int key) {
        auto &[val, freq] = keyToValFreq[key];
        int oldFreq = freq;

        // remove from old frequency list
        freqToList[oldFreq].erase(keyToIter[key]);

        // if old list empty and oldFreq == minFreq, update minFreq
        if (freqToList[oldFreq].empty()) {
            freqToList.erase(oldFreq);
            if (oldFreq == minFreq) minFreq++;
        }

        // add to new freq list
        freq++;
        freqToList[freq].push_front(key);
        keyToIter[key] = freqToList[freq].begin();
    }

public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        this->minFreq = 0;
    }

    int get(int key) {
        if (capacity == 0 || keyToValFreq.count(key) == 0)
            return -1;

        updateFreq(key);
        return keyToValFreq[key].first;
    }

    void put(int key, int value) {
        if (capacity == 0) return;

        // if key already exists
        if (keyToValFreq.count(key)) {
            keyToValFreq[key].first = value; // update value
            updateFreq(key);
            return;
        }

        // if full → remove LFU + LRU key
        if (keyToValFreq.size() == capacity) {
            int keyToRemove = freqToList[minFreq].back();
            freqToList[minFreq].pop_back();

            if (freqToList[minFreq].empty())
                freqToList.erase(minFreq);

            keyToIter.erase(keyToRemove);
            keyToValFreq.erase(keyToRemove);
        }

        // new key inserted with freq = 1
        keyToValFreq[key] = {value, 1};
        freqToList[1].push_front(key);
        keyToIter[key] = freqToList[1].begin();
        minFreq = 1;
    }
};

class Heap {
public:
    Heap(int cap): cap(cap), size(0) {
        data = new pair<int, int>[cap];
    }
    ~Heap() {
        delete [] data;
    }

    void insert(int key, int val) {
        if (full()) {
            if (val <= data[0].second) {
                return;
            }

            data[0] = {key, val};

            siftDown(0);
        } else {
            data[size] = {key, val};
            bubbleUp(size++);
        }
    }

    //private:
    void siftDown(int idx) {
        int min = idx;
        int left = 2 * idx + 1;
        int right = 2 * idx + 2;

        if (left < size && data[min].second > data[left].second) {
            min = left;
        }

        if (right < size && data[min].second > data[right].second) {
            min = right;
        }

        if (min != idx) {
            swap(idx, min);
            siftDown(min);
        }
    }

    void bubbleUp(int idx) {
        int parent = (idx - 1) / 2;

        while (parent >= 0 && data[idx].second < data[parent].second) {
            swap(parent, idx);
            idx = parent;
            parent = (idx - 1) / 2;
        }
    }

    void swap(int i, int j) {
        auto tmp = data[i];

        data[i] = data[j];
        data[j] = tmp;
    }

    bool full() {
        return cap == size;
    }

    int cap, size;
    pair<int, int> *data;
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        Heap heap(k);
        unordered_map<int, int> map;

        for (auto val : nums) {
            ++map[val];
        }

        for (auto &p : map) {
            heap.insert(p.first, p.second);
        }

        vector<int> ret;

        for (int i = 0; i < heap.size; ++i) {
            ret.push_back(heap.data[i].first);
        }

        return ret;
    }
};

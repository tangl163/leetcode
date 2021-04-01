class Node {
public:
    Node(int key, int val): key(key), val(val), next(nullptr), prev(nullptr) {}
    int key, val;
    Node *next, *prev;
};

class DoubleLinkedList {
public:
    DoubleLinkedList(int cap): cap(cap), size(0), head(nullptr), tail(nullptr) {}
    Node *insert(int key, int val) {
        Node *node = new Node(key, val);

        node->next = head;
        if (head != nullptr) {
            head->prev = node;
        }

        head = node;
        if (tail == nullptr) {
            tail = node;
        }

        ++size;

        return node;
    }

    void remove(Node *node) {
        if (head == node) {
            head = node->next;
        }

        if (tail == node) {
            tail = node->prev;
        }

        if (node->next != nullptr) {
            node->next->prev = node->prev;
        }

        if (node->prev != nullptr) {
            node->prev->next = node->next;
        }

        --size;
        delete node;
    }

    void promote(Node *node) {
        if (node == head) {
            return;
        }

        if (node == tail) {
            tail = node->prev;
            tail->next = nullptr;
        }

        if (node->next != nullptr) {
            node->next->prev = node->prev;
        }

        node->prev->next = node->next;
        node->next = head;
        head->prev = node;
        node->prev = nullptr;
        head = node;
    }

    Node *pop_back() {
        if (empty()) {
            return nullptr;
        }

        Node *ret = tail;

        if (head == tail) {
            head = tail = nullptr;
        } else {
            tail = tail->prev;
            tail->next = nullptr;
        }

        --size;
        ret->prev = nullptr;

        return ret;
    }

    int empty() {
        return size == 0;
    }

    int full() {
        return cap == size;
    }
private:
    int cap, size;
    Node *head, *tail;
};

class LRUCache {
public:
    LRUCache(int cap): dbList(cap) {}

    int get(int key) {
        auto tmp = map.find(key);

        if (tmp != map.end()) {
            dbList.promote(tmp->second);

            return tmp->second->val;
        }

        return -1;
    }

    void put(int key, int value) {
        auto tmp = map.find(key);

        if (tmp != map.end()) {
            tmp->second->val = value;
            dbList.promote(tmp->second);
        } else {
            if (dbList.full()) {
                Node *evict = dbList.pop_back();
                map.erase(evict->key);
                delete evict;
            }

            Node *p = dbList.insert(key, value);
            map[key] = p;
        }
    }
private:
    DoubleLinkedList dbList;
    unordered_map<int, Node *> map;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

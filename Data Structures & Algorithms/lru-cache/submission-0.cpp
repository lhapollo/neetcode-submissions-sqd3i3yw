#include <unordered_map>
using namespace std;

class Node {
public:
    int key;
    int val;
    Node* prev;
    Node* next;

    Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
};

class LRUCache {
public:
    int cap;
    unordered_map<int, Node*> um;

    Node* head; // dummy head (LRU side)
    Node* tail; // dummy tail (MRU side)

    LRUCache(int capacity) {
        cap = capacity;

        head = new Node(0, 0);
        tail = new Node(0, 0);

        head->next = tail;
        tail->prev = head;
    }

    // remove node from list
    void remove(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    // insert node right before tail (MRU position)
    void insertMRU(Node* node) {
        node->prev = tail->prev;
        node->next = tail;
        tail->prev->next = node;
        tail->prev = node;
    }

    int get(int key) {
        if (!um.count(key)) return -1;

        Node* node = um[key];
        remove(node);
        insertMRU(node);
        return node->val;
    }

    void put(int key, int value) {
        if (um.count(key)) {
            // update existing
            Node* node = um[key];
            node->val = value;
            remove(node);
            insertMRU(node);
        } else {
            // insert new
            if (um.size() == cap) {
                // evict LRU (first real node after head)
                Node* lru = head->next;
                remove(lru);
                um.erase(lru->key);
                delete lru;
            }

            Node* node = new Node(key, value);
            um[key] = node;
            insertMRU(node);
        }
    }
};

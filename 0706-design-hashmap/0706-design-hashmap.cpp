class MyHashMap {
    struct ListNode {
        int key;
        int val;
        ListNode* next;

        ListNode(int k = -1, int v = -1) : key(k), val(v), next(nullptr) {}
    };

    const int hashSize;
    vector<ListNode*> hashTable;

    int hash(int key) {
        return key % hashSize;
    }

public:
    MyHashMap() : hashSize(10009), hashTable(hashSize, nullptr) {}

    void put(int key, int value) {
        int hashIdx = hash(key);
        ListNode* curr = hashTable[hashIdx];
        while (curr) {
            if (curr->key == key) {
                curr->val = value;
                return;
            }
            curr = curr->next;
        }
        ListNode* newNode = new ListNode(key, value);
        newNode->next = hashTable[hashIdx];
        hashTable[hashIdx] = newNode;
    }

    int get(int key) {
        int hashIdx = hash(key);
        ListNode* curr = hashTable[hashIdx];
        while (curr) {
            if (curr->key == key) {
                return curr->val;
            }
            curr = curr->next;
        }
        return -1;
    }

    void remove(int key) {
        int hashIdx = hash(key);
        ListNode* curr = hashTable[hashIdx];
        if (curr && curr->key == key) {
            hashTable[hashIdx] = curr->next;
            delete curr;
            return;
        }
        while (curr && curr->next) {
            if (curr->next->key == key) {
                ListNode* temp = curr->next;
                curr->next = curr->next->next;
                delete temp;
                return;
            }
            curr = curr->next;
        }
    }
};


/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
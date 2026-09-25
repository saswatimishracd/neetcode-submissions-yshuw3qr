class LRUCache {
   public:
    // Define a doubly linked list node
    int capacity;
    struct Node {
        int key;
        int value;
        Node* prev;
        Node* next;

        Node(int key, int value) {
            this->key = key;
            this->value = value;
            prev = nullptr;
            next = nullptr;
        }
    };
    unordered_map<int, Node*> mp;

    // create LRU and MRU
    Node* lru = nullptr;
    Node* mru = nullptr;

    LRUCache(int capacity) { this->capacity = capacity; }

    int get(int key) {
        if (mp.find(key) == mp.end()) {
            return -1;
        } else {
            Node* temp = mp[key];
            if (lru == mru)
                return temp->value;
            else if (lru == temp) {
                lru = lru->next;
                if (lru != nullptr) {
                    lru->prev = nullptr;
                }

                temp->prev = mru;
                temp->next = nullptr;

                mru->next = temp;
                mru = temp;
            } else if (mru == temp) {
                return temp->value;
            } else {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;

                temp->prev = mru;
                temp->next = nullptr;
                mru->next = temp;
                mru = temp;

                mp[key] = mru;
            }
        }
        return mp[key]->value;
    }

    void put(int key, int value) {
        if (lru == nullptr) {
            Node* newNode = new Node(key, value);
            mp[key] = newNode;
            lru = newNode;
            mru = newNode;
        } else if (mp.find(key) != mp.end()) {
            Node* temp = mp[key];
            temp->value = value;
            if (temp == mru) {
                return;
            } else if (temp == lru) {
                lru = lru->next;
                if (lru != nullptr) {
                    lru->prev = nullptr;
                }

                temp->prev = mru;
                temp->next = nullptr;

                mru->next = temp;
                mru = temp;
            }

            else {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;

                temp->prev = mru;
                temp->next = nullptr;
                mru->next = temp;
                mru = temp;
                mru->value = value;
                mp[key] = mru;
            }
        } else if (mp.size() == capacity) {
            Node* temp = lru;
            mp.erase(lru->key);
            lru = lru->next;

            if (lru != nullptr) {
                lru->prev = nullptr;
            }
            if(mru==temp) mru=nullptr;
            delete (temp);
            Node* newNode = new Node(key, value);
            if (mru == nullptr) {
                mru = newNode;
                lru = newNode;
            } else {
                mru->next = newNode;
                newNode->prev = mru;
                mru = newNode;
            }
                mp[key] = mru;

        } else {
            Node* newNode = new Node(key, value);
            mru->next = newNode;
            newNode->prev = mru;
            mru = mru->next;
            mp[key] = mru;
        }
    }
};

class LRUCache {
public:
    class node{
        public:
        int key, val;
        node *left, *right;
        node(int _key, int _val) {
            key = _key;
            val = _val;
        }
    };
    node *head = new node(-1, -1);
    node *tail = new node(-1, -1);
    int cap;
    unordered_map<int, node*> u;
    
    void addNode(node* n) {
        node* temp = head->right;
        n->left = head;
        n->right = temp;
        head->right = n;
        temp->left = n;
        u[n->key] = n;
    }
    
    void removeNode(node* n) {
        node* prevNode = n->left;
        node* nextNode = n->right;
        prevNode->right = nextNode;
        nextNode->left = prevNode;
        u.erase(n->key);
    }
    
    LRUCache(int capacity) {
        cap = capacity;
        head->right = tail;
        tail->left = head;
    }
    
    int get(int key) {
        if(u.find(key)!=u.end()) {
            node* existingNode = u[key];
            removeNode(existingNode);
            addNode(existingNode);
            return existingNode->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(u.find(key)!=u.end()) {
            node* existingNode = u[key];
            removeNode(existingNode);
            existingNode->val = value;
            addNode(existingNode);
        } else {
            node *nn = new node(key, value);
            if(u.size()==cap){
                removeNode(tail->left);
            }
            addNode(nn);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
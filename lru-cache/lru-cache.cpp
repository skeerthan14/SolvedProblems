class Node {
    public:
    int key, val;
    Node *left, *right;
    Node(int _key, int _val) {
        key = _key;
        val = _val;
    }
};

class LRUCache {
public:
    Node *head = new Node(-1,-1);
    Node *tail = new Node(-1,-1);
    unordered_map<int, Node*> u;
    int cap;
    LRUCache(int capacity) {
        cap = capacity;
        head->right = tail;
        tail->left = head;
    }
    
    void remove(Node* n) {
        n->left->right = n->right;
        n->right->left = n->left;
        // free(n);
        u.erase(n->key);
        // Node* prevNode = n->left;
        // Node* nextNode = n->right;
        // prevNode->right = nextNode;
        // nextNode->left = prevNode;
        // u.erase(n->key);
    }
    
    void add(Node* n) {
        Node* temp = head->right;
        n->left = head;
        n->right = temp;
        head->right = n;
        temp->left = n;
        u[n->key] = n;
    }
    
    int get(int key) {
        int val;
        if(u.find(key)!=u.end()) {
            Node* existingNode = u[key];
            val = u[key]->val;
            remove(u[key]);
            add(existingNode);
            return val;
        } 
        return -1;
    }
    
    void put(int key, int value) {
        // Node* temp = new Node(key, value);
        // u[key] = temp;
        // if(cap<u.size()) {
        //     head->right->left = temp;
        //     temp->right = head->right;
        // } else {
        //     remove(tail->left);
        //     head->right->left = temp;
        //     temp->left = head;
        //     temp->right = head->right;
        //     head->right = temp;
        // }
        if(u.find(key)!=u.end()) {
            Node* existingNode = u[key];
            remove(existingNode);
            existingNode->val = value;
            add(existingNode);
        } else {
            Node *nn = new Node(key, value);
            if(u.size()==cap){
                remove(tail->left);
            }
            add(nn);
        }
            
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
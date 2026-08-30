class LRUCache {
public:
    // we will use a Doubly Linked List
    // In which we store MRU at head of list
    // & LRU at tail of list

    class Node{
        public:
            int key;
            int val;
            Node* prev;
            Node* next;

            Node(int k,int v){
                key = k;
                val = v;
                prev = next = nullptr;
            }
    };

    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);

    unordered_map<int,Node*> m;
    int limit;

    void AddNode(Node* NewNode){
        Node* NextNode = head->next;
        
        head->next = NewNode;
        NewNode->prev = head;

        NewNode->next = NextNode;
        NextNode->prev = NewNode;
    }

    void DeleteNode(Node* node){
        Node* prevNode = node->prev;
        Node* nextNode = node->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }


    LRUCache(int capacity) {
        limit = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(m.find(key) == m.end()){
            return -1;
        }

        Node* node = m[key];

        DeleteNode(node);
        m.erase(key);
        AddNode(node);
        m[key] = node;

        return node->val;
    }
    
    void put(int key, int value) {
        if(m.find(key) != m.end()){
            Node* node = m[key];

            DeleteNode(node);
            m.erase(key);
        }

        if(m.size() == limit){
            Node* node = tail->prev;

            DeleteNode(node);
            m.erase(node->key);
        }

        Node* newNode = new Node(key,value);

        m[key] = newNode;
        AddNode(newNode);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
class LFUCache {
public:
    class Node{
        public:
        int key;
        int val;
        int freq;
        Node* prev;
        Node* next;

        Node(int k,int v){
            key = k;
            val = v;
            freq = 1;
            prev = nullptr;
            next = nullptr;
        }
    };

    class List{
        public:
        int size;
        Node* head;
        Node* tail;

        List(){
            size = 0;
            head = new Node(-1,-1);
            tail = new Node(-1,-1);
            head->next = tail;
            tail->prev = head;
        }

        void addNode(Node* node){
            Node* temp = head->next;

            head->next = node;
            node->prev = head;
            node->next = temp;
            temp->prev = node;
            size++;
        }

        void delNode(Node* node){
            Node* nextNode = node->next;
            Node* prevNode = node->prev;

            prevNode->next = nextNode;
            nextNode->prev = prevNode;
            size--;
        }
    };

    // it stores freq & the DLL of nodes
    // MRU elements at head of DLL
    // LRU elements at tail of DLL
    unordered_map<int,List*> freqMap;

    // it key & node
    unordered_map<int,Node*> m;

    int minFreq;
    int Capacity;

    LFUCache(int capacity) {
        Capacity = capacity;
        minFreq = 0;
    }
    
    int get(int key) {
        if(m.find(key) == m.end()){
            return -1;
        }

        Node* node = m[key];

        freqMap[node->freq]->delNode(node);
        if(minFreq == node->freq && freqMap[node->freq]->size == 0){
            minFreq++;
        }

        node->freq += 1;

        if(freqMap.find(node->freq) == freqMap.end()){
            freqMap[node->freq] = new List();
        }

        freqMap[node->freq]->addNode(node);

        return node->val;
    }
    
    void put(int key, int value) {
        if(m.find(key) != m.end()){
            Node* node = m[key];

            node->val = value;

            freqMap[node->freq]->delNode(node);
            if(minFreq == node->freq && freqMap[node->freq]->size == 0){
                minFreq++;
            }

            node->freq += 1;

            if(freqMap.find(node->freq) == freqMap.end()){
                freqMap[node->freq] = new List();
            }
            freqMap[node->freq]->addNode(node);
            return;
        }

        if(m.size() == Capacity){
            List* l = freqMap[minFreq];

            Node* node = l->tail->prev;

            l->delNode(node);
            m.erase(node->key);

            delete node;
        }

        Node* newNode = new Node(key,value);
        
        m[key] = newNode;

        if(freqMap.find(1) == freqMap.end()){
            freqMap[1] = new List();
        }

        freqMap[1]->addNode(newNode);
        minFreq = 1;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
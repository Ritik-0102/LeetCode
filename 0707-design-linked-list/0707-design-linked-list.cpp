class MyLinkedList {
public:
    class Node{
        public:
        int val;
        Node* next;

        Node(int value){
            val = value;
            next = nullptr;
        }
    };

    int length;
    Node* head;

    MyLinkedList() {
        this->head = nullptr;
        this->length = 0;
    }
    
    int get(int index) {
        if(index >= this->length){
            return -1;
        }

        Node* temp = this->head;
        for(int i=0;i<index;i++){
            temp = temp->next;
        }
        return temp->val;
    }
    
    void addAtHead(int val) {
        if(this->length == 0){
            head = new Node(val);
            this->length++;
            return;
        }

        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
        this->length++;
    }
    
    void addAtTail(int val) {
        if(this->length == 0){
            head = new Node(val);
            this->length++;
            return;
        }
        
        Node* temp = head;
        for(int i=0;i<this->length - 1;i++){
            temp = temp->next;
        }

        Node* newNode = new Node(val);
        temp->next = newNode;
        this->length++;
    }
    
    void addAtIndex(int index, int val) {
        if(index > this->length){
            return;
        }
        if (index == 0) {
            addAtHead(val);
            return;
        }
        if(this->length == 0){
            head = new Node(val);
            this->length++;
            return;
        }
        
        Node* temp = head;
        for(int i=0;i<index-1;i++){
            temp = temp->next;
        }
        
        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
        this->length++;
    }
    
    void deleteAtIndex(int index) {
        if(index >= this->length){
            return;
        }

        if(index == 0){
            head = head->next;
            this->length--;
            return;
        }
        
        Node* temp = head;
        for(int i=0;i<index-1;i++){
            temp = temp->next;
        }
        
        temp->next = temp->next->next;
        this->length--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
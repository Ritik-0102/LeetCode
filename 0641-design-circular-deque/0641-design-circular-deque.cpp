class MyCircularDeque {
public:
    vector<int> dq;
    int size;
    int capacity;
    int front;
    int rear;
    MyCircularDeque(int k) {
        dq.assign(k,0);
        capacity = k;
        size = 0;
        front = 0;
        rear = 0;
    }
    
    bool insertFront(int value) {
        if(size >= capacity){
            return false;
        }

        front = (front + capacity - 1) % capacity;
        dq[front] = value;
        size++;
        return true;
    }
    
    bool insertLast(int value) {
        if(size >= capacity){
            return false;
        }

        dq[rear] = value;
        rear++;
        size++;
        rear %= capacity;
        return true;
    }
    
    bool deleteFront() {
        if(size == 0){
            return false;
        }
        front++;
        size--;
        front %= capacity;
        return true;
    }
    
    bool deleteLast() {
        if(size == 0){
            return false;
        }
        rear = (rear + capacity - 1) % capacity;
        size--;
        return true;
    }
    
    int getFront() {
        if(size == 0){
            return -1;
        }
        return dq[front];
    }
    
    int getRear() {
        if(size == 0){
            return -1;
        }
        return dq[(rear + capacity - 1)%capacity];        
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == capacity;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
class MyCircularQueue {
public:
    vector<int> arr;
    int size;
    int capacity;
    int front;
    int rear;
    MyCircularQueue(int k) {
        arr.assign(k,0);
        capacity = k; 
        size = 0;
        front = 0;
        rear = 0;
    }
    
    bool enQueue(int value) {
        if(size < capacity){
            arr[rear] = value;
            rear++;
            size++;
            rear %= capacity;
            return true;
        }
        return false;
    }
    
    bool deQueue() {
        if(size > 0){
            front++;
            size--;
            front %= capacity;
            return true;
        }
        return false;        
    }
    
    int Front() {
        if(size == 0){
            return -1;
        }
        return arr[front];
    }
    
    int Rear() {
        if(size == 0){
            return -1;
        }
        return arr[(rear + capacity - 1) % capacity];
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == capacity;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
#include<vector>
#include<iostream>
using namespace std;

class MyCircularQueue {

    private :
    vector<int> queue;
    int head;
    int tail;
    int length;
    public:
     /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k){
      queue.resize(k);
        head = -1;
        tail = -1;
        length = k;   
    }
    
    bool enQueue(int value) {
       if(isFull()){
           return false;
       }
        
        if(isEmpty()){
            head =0;
        }
        
        tail = (tail+1)%length;
        
        queue[tail] = value;
        cout<<"enqueue : "<<value<<" head : "<<head<<" tail : "<<tail<<endl;
        return true;
    }
    
     /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        cout<<head<<"  "<<tail<<endl;
        if(isEmpty()){
            return false;
        }
        
        if(head == tail){
            head = -1;
            tail = -1;
            return true;
        }
        
      
        
        head = (head+1) % length;
        return true;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        if(isEmpty()){
            return -1;
        }
        return queue[head];
        
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        if(isEmpty()){
            return -1;
        }
        return queue[tail];
    }
    
    bool isEmpty(){
       return head == -1 ? true : false;
    }
    
    bool isFull(){
        return ((tail+1) % length == head) ? true : false;
    }
  
};

int main(){
    MyCircularQueue* obj = new MyCircularQueue(6);
    bool param_1 = obj->enQueue(6);
    
    int param_2 = obj->Rear();
    int param_3 = obj->Rear();
    bool param_4 = obj->deQueue();
    cout<<param_1<<" "<<param_2<<" "<<param_3<<" "<<param_4;
}

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
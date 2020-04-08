#include<iostream>
#include<vector>

using namespace std;
/**
 * Basic Queue implementation
 * 
 * 
 * 
*/
class Queue {
    
    private :
    vector<int> data;
    
    int point;
    public:
    
    Queue(){
        point = 0;
    }
    
    // insert data at end
    bool enQueue(int value){
        data.push_back(value);
        
        return true;
    }
    
    // delete element from front and point to next element
    bool deQueue(){
      if(!isEmpty()){
          
          point++;
          return true;
      }else {
          cout<<"tree is empty";
      }
    }
    
    // check is empty or not
    bool isEmpty(){
      return data.size() <= point ? true:false;
    }
    
    // return first element of queue
    int front(){
        return data[point];
    }
    
    
    
};

int main(){

    Queue d;
    d.enQueue(5);
    d.enQueue(10);
    d.enQueue(15);
    cout<<d.front()<<endl;
    d.deQueue();
    cout<<d.front()<<endl;
    d.deQueue();
    cout<<d.front()<<endl;
    
}
#include<iostream>

using namespace std;

class Node {
  public:
    int data;
    Node* next;
};


Node* creation(){
  Node* temp;
  temp = new Node();
  temp->next = NULL;
  return temp;
}

Node* deletion(Node* head,int index){
  Node* temp;
  Node* current;
  if(head == NULL){
    cout<<"no element exist for delete"<<endl;
    return head;
  }
  else if(index == 1){
    temp = head;
    head = head->next;
    free(temp);
  }
  else if(index == -1){
    current = head;
    while(current->next->next != NULL){
      current = current->next;
    }
    temp = current->next;
    current->next = NULL;
    free(temp);
  }
  else {
   current = head;
    for(int i =1; i<index-1; i++){
      current = current->next;
    }
   temp = current->next;
    current->next= current->next->next;
    free(temp);
  }
  
  return head;
}

Node* traversing(Node* head){
  
  Node* current;
  current= head;
  if(head == NULL){
    cout<<"!!!.........no element exist"<<endl;
  }else {
    int count = 0 ;
    while(current != NULL){
      count++;
      cout<<" index is "<<count<<" value is "<<current->data<<endl;
      current = current->next;
    }
  }
  
  return head;
}

Node* insertion(Node* head,Node* temp,int index, int value){
  if(index == 1){
    Node* firstNode = head;
    temp->next = firstNode;
    temp->data =value;
    head = temp;
    
  }
  else if(index == -1){
    Node* currentNode = head;
      if(head != NULL){
        while(currentNode->next != NULL){
        cout<<currentNode->data<<"  ";
        currentNode = currentNode->next;
        }
         temp->data = value;
          currentNode->next = temp;
      }else {
        temp->data = value;
        head = temp;
      }
  }
  else {
  
    Node* currentNode = NULL;
    currentNode = head;
    
    for(int i=1 ; i<index-1 ; i++){
      cout<<"i is : "<<i<<endl;
      currentNode = currentNode->next;
    }
    
    temp->data = value;
    temp->next = currentNode->next;
    currentNode->next = temp;
  }
  
  return head;
}

Node* reverse(Node* head){
  Node* previous;
  Node* current;
  Node* end;
  
    previous = NULL;
    end = NULL;
    current = head;
    while(current != NULL){
      end = current->next;
      current->next = previous;
      previous = current;
      current =end;
      
    }
  head = previous;
  return head;
  
  
}
int main(){
  
  Node* head = NULL;
  Node* temp = NULL;
  Node* currentNode = NULL;
  cout<<"program Begins";
  int input;
  
  do{
    cout<<endl<<"--------------------------"<<endl;
    cout<<"enter the operation which you want to perform"<<endl<<"1.insertion at top 2. insert at index 3. insertion in end"<<endl;
    cout<<"4. delete last element 5. delete top element 6. delete at index"<<endl;
    cout<<"7. traversing 8. reverse 10. Exit"<<endl;
    cin>>input;
    int value;
    if(input == 1){
      // node will get created
      temp = creation();
      cout<<"enter value to insert at top"<<endl;
      cin>>value;
      
      head = insertion(head , temp, 1, value);
      currentNode = head;

      
    }
    
    if(input == 2){
      
      int index;
      temp = creation();
      cout<<"enter value to insert"<<endl;
      cin>>value;
      cout<<"insert index at where you want to insert"<<endl;
      cin>>index;
      
      head = insertion(head , temp, index, value);
      currentNode = head;

    }
    
    if(input == 3){
      cout<<"enter value to insert at end"<<endl;
      cin>>value;
      temp = creation();
      head = insertion(head , temp, -1, value);
      currentNode = head;

    }
    if(input ==4){
     head = deletion(head , -1);
    }
    if(input == 5){
      head = deletion(head , 1);
    }
    
    if(input == 6){
      int index;
      cout<<"enter index to delete"<<endl;
      cin>>index;
      head = deletion(head,index);
    }
    if(input == 7){
      traversing(head);
    }
    if(input ==8){
      head = reverse(head);
    }
    if(input == 10){
      cout<<"exiting....!!!"<<endl;
    }
    
  }while(input !=10);
}


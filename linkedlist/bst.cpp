#include<iostream>

using namespace std;

class Node {
  public:
  Node* left;
  int data;
  Node* right;
};

Node* creation(){
  Node* temp = new Node();
  temp->left = NULL;
  temp->right = NULL;
  return temp;
  
}

Node* Inordertraversing(Node* root){
  
  if(root == NULL){
    cout<<"No element exist"<<endl;
  }
  
  if(root->left !=NULL){
    root->left = Inordertraversing(root->left);
  }
  
  cout<<root->data<<" ";
  
  if(root->right !=NULL){
    root->right = Inordertraversing(root->right);
  }
  return root;
  
}

Node* findLeftMostElement(Node* root){
    while(root && root->left != NULL){
        root = findLeftMostElement(root->left);
    }
    return  root;
}


Node* deleteNode(Node* root, int key){
  if(root == NULL){

    return root;
  }

   if (key < root->data) 
    root->left = deleteNode(root->left, key); 
  else if (key > root->data) 
    root->right = deleteNode(root->right, key); 
  else{
    cout<<root->data<<endl;
       if(root->left == NULL){
           Node* temp = root->right;
           free(root);
           return temp;
       }
       else if(root->right == NULL){
           Node* temp = root->left;
           free(root);
           return temp;
       }else {
           Node* leftElement = findLeftMostElement(root->right);
           root->data = leftElement->data;
           root->right = deleteNode(root->right, leftElement->data);
       }
   }
  
  return root;
}

Node* insertion(Node* root, int data){
  Node* temp;
  if(root == NULL){
  
    temp = creation();
    temp->data = data;
    return temp;
  }
  
  if(root->data > data){
  
    root->left = insertion(root->left , data);
  }
  else if(root->data < data){
    root->right = insertion(root->right, data);
  }
  
  return root;
}

int main(){
    Node* root= NULL;
    root = insertion(root, 100);
    insertion(root, 50);
    insertion(root, 180);
    insertion(root, 30);
    insertion(root, 120);
    insertion(root, 200);
    insertion(root,90);
    
    insertion(root, 10);
    insertion(root, 35);
    insertion(root, 55);
    insertion(root, 95);
    insertion(root, 110);
    insertion(root, 140);
    insertion(root, 190);
    insertion(root, 210);
    Inordertraversing(root);
    cout<<endl;
    cout<<"deleting"<<endl;
    root=deleteNode(root, 10);
    cout<<"---"<<endl;
    cout<<root->data<<endl;
    cout<<"traversing "<<endl;
    Inordertraversing(root);
    root=deleteNode(root, 110);
    cout<<"---"<<endl;
    cout<<root->data<<endl;
    cout<<"traversing "<<endl;
    Inordertraversing(root);
    root=deleteNode(root, 180);
    cout<<"---"<<endl;
    cout<<root->data<<endl;
    cout<<"traversing "<<endl;
    Inordertraversing(root);
    root=deleteNode(root, 100);
    cout<<"---"<<endl;
    cout<<root->data<<endl;
    cout<<"traversing "<<endl;
    Inordertraversing(root);

  
}
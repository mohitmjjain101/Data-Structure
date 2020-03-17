// This program show to jump to at index using pointer math

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int getValue(int *ptr,int *capcity, int index){
  if(index>*capcity){
    cout<<"index out of bound"<<endl;
  }else {
    int &value = *(ptr + index);
    cout<<"value at index "<<index<<" is "<<value<<endl;
  }
  
}

int insertAtIndex(int *ptr , int *capcity, int *sizeptr, int value, int index){
  if(index > *capcity){
    cout<<"index is out of range. Please insert in the range (0,"<<(*capcity-1)<<")"<<endl;
  }else {
    int &address = *(ptr + index);
    address = value;
  }
  
}

int resize(int *ptr , int *capcity, int *sizeptr, int flag, int value){
  int newcapacity;
  if(flag == 0){
    newcapacity = *capcity * 2;
  }else {
//     cout<< value<<" : "<<*sizeptr;
    if(value < *sizeptr){
      cout<<"resize do not proceed you will lost element"<<endl;
    }else{
      newcapacity = value;
    }
  }
 
  int array [newcapacity];
  *capcity = newcapacity;
  for(int i=0 ; i<*sizeptr ; i++){
    array[i] = *(ptr + i);
  }
  
}
int pushBack(int *ptr,int *sizeptr,int *capacity,  int value){
  if(*capacity < *sizeptr +1){
    //double the size of array and copy all element to another array
    resize(ptr, capacity, sizeptr ,0 ,0);
  }
    int &address  = *(ptr + *sizeptr);
    address = value;
    int &size = *sizeptr;
    size= size+1;
}


int main(){
  
  int array[1];
  int size = 0;
  
  int capacity = 1;
  int *ptr ;
  ptr = array;
  
  int * sizeptr ;
  sizeptr = &size;
  
  int * capacityptr;
  capacityptr = &capacity;
  int input;
  
  do {
    cout<<"enter the operation which you want to perform"<<endl;
    cout<<"1 : pushback 2: get size 3. capacity 4. resize 5.insert at an index 6. get value at index 10.exit"<<endl;
    cin>>input;
    if(input == 1){
      int value;
      cout<<"enter value which you want to save"<<endl;
      cin>>value;
       pushBack(ptr,sizeptr, capacityptr, value);
      for(int i =0 ; i <*sizeptr ;i++){
      cout<<"value is at index "<<i<<" is "<< *(ptr+i)<<endl<<endl;
      }
    
    }
    if(input ==2){
      cout<<"size is : :"<<*sizeptr<<endl;
    }
    if(input == 3){
      cout<<"capacity is : :"<<*capacityptr<<endl;
    }
    if(input ==4){
      cout<<"enter new capacity for resize "<<endl;
      int newcapcaity;
      cin>>newcapcaity;
      resize(ptr, capacityptr, sizeptr ,1,newcapcaity);
    }
    if(input == 5){
      int value, index;
      cout<<"enter value which you want to insert"<<endl;
      cin>>value;
      cout<<"enter index"<<endl;
      cin>>index;
      insertAtIndex(ptr, capacityptr, sizeptr, value, index);
       for(int i =0 ; i <*sizeptr ;i++){
      cout<<"value is at index "<<i<<" is "<< *(ptr+i)<<endl<<endl;
      }
    }
    if(input == 6){
      int index;
      cout<<"enter index"<<endl;
      cin>>index;
      cout<<endl;
      getValue(ptr, capacityptr, index);
    }
  }while(input != 10);
  
  
}
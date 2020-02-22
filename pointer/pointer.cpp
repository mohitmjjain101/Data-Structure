#include<iostream>

using namespace std;
int main(){
  
  int c = 10;
  
  int *p;
  
  p = &c;
  
  cout<<*p<<endl;
  cout<<p<<endl;
  cout<<c<<endl;
  cout<<&p<<endl;
  cout<<&c<<endl;
  
}
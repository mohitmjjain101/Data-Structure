#include<iostream>

using namespace std;
void primeNumber(int n){
  
  int arr[n];
  for(int i=0 ; i<n; i++){
    arr[i] = 1;
  }
  for(int i=2; i*i <n ; i++){
     for(int j=2*i ; j<n ; j=j+i){
         if(arr[j] == 1){
           arr[j] = 0;
         }
     }
  }
  
  for(int i=1 ; i<n ; i++){
    if(arr[i]==1){
      cout<<i<<endl;
    }
  }
}

int main(){
  // making prime no program
  int n;
  cout<<"enter the no of elements to find out prime no";
  cin>> n;
  primeNumber(n+1);
}



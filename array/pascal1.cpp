#include<iostream>
#include<vector>
using namespace std;

void pascalTraingle(int n){

  vector<vector<int>> pascal(n);
   
  for(int i=0 ; i< pascal.size(); i++){

    pascal[i].resize(i+1);
    pascal[i][0]= 1;
    for(int j =0 ; j<i ; j++){
      
      pascal[i][j]= pascal[i-1][j-1]+ pascal[i-1][j];
    }
    pascal[i][i]= 1;
  }
  
  
  for(int i = 0; i<pascal.size(); i++){
    for(int j=0 ; j<pascal[i].size(); j++){
      cout<< pascal[i][j] <<" ";
    }
    cout<<endl;
  }
}

int main(){
  int n;
  cout<< "please enter no of row to print pascal triangle";
  cin>>n;
  pascalTraingle(n);
}

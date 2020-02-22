#include <iostream>
using namespace std;

int swap(int &x , int &y){
//   cout<<x<<<<endly<<endl;
  cout<<"---------"<<endl;
  cout<<&x<<endl<<&y;
}


int main()
{
  int a= 10;
  int b = 10;

  cout<<&a <<endl<<&b<<endl;
    swap(a,b);
}
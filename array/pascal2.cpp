#include<bits/stdc++.h>
using namespace std;
int main()
{
    // size of row
    int row ;
    cin>>row;
 
    vector<vector<int> > vec(row);
 
    for (int i = 0; i < row; i++) {
 
        vec[i].resize(i+1);
        vec[i][0]=1;
         vec[i][i]=1;
        for (int j = 0; j < i; j++) {
         
                  vec[i][j]=vec[i-1][j-1]+vec[i-1][j];
        }
    }
 
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < vec[i].size(); j++)
            cout << vec[i][j] << " ";
        cout << endl;
    }
}
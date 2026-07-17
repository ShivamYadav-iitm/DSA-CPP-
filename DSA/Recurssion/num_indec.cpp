#include<iostream>
using namespace std;


void dec(int n){
    if(n==0){   //base case
        return; 
    }
    cout<<n<<" ";  //work we have to do
    dec(n-1);      //assumption , faith
}
int main(){
    int n=5;
    dec(n);
    return 0;
}
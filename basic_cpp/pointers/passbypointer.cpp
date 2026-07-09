#include<iostream>
using namespace std;

//pass by reference using pointer
void changeA(int *ptr){
    *ptr = 20;
    cout<<*ptr;
}

//pass by reference using reference variable
void changeA(int &b){
    b = 20;
    cout<<b;
}


int main(){
    int a = 10;;
    changeA(a);
    cout<<"\n"<<a;
}
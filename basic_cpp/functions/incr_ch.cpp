#include<iostream>
using namespace std;

void incr(){
    char a;
    cout<<"Enter a character: ";
    cin>>a;
    char b = a+1;
    cout<<b;

    if(a == 'z'){
        cout<<"a";
    }
}

int main(){
    incr();
    return 0;
}
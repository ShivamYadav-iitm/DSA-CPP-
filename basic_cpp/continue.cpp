#include <iostream>
using namespace std;

int main(){
    int num;
    do{
        cout<<"Enter number: ";
        cin>>num;
        if(num %10 == 0){
            continue;
        }
        cout<<"you entered :"<<num<<"\n";

    }while(true);
}
#include<iostream>
using namespace std;

int main(){
    int num;
    cout<<"Enter number: ";
    cin>>num;
    bool isprime = true;
    for(int i=2;i<num;i++){
        if(num % i == 0){
            isprime = false;
            cout<<"\nThe number is not a prime number";
            break;
        }
    }

    if(isprime){
        cout<<"\nThe number is a prime number";
    }

    return 0;
}
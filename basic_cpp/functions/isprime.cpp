#include<iostream>
using namespace std;

bool prime = true;

bool isprime(int x){
    for(int i=2;i<x;i++){
        if(x%i==0){
            prime = false;
        }
    }
    return prime;
}

int main(){
    isprime(18);
    if(prime){
        cout<<"the number is prime";
    }
    else{
        cout<<"the number is not prime";
    }
    return 0;
}
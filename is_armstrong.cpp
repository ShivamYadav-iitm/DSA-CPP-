#include<iostream>
using namespace std;

int main(){
    int num;
    cout<<"Enter num to check: ";
    cin>>num;
    int sum = 0;
    int lastdig = num % 10;
    int rum = num;

    while(rum != 0){
        int cube = lastdig*lastdig*lastdig;
        sum = sum + cube;
        rum = rum/10; 
        lastdig = rum % 10;  
    }
    if(sum == num){
        cout<<"The entered number is a armstrong number";
    }
    else{
        cout<<"The entered number is not a armstrong number";
    }
    return 0;
}
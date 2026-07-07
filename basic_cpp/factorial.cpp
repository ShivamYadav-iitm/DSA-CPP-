#include<iostream>
using namespace std;

int main(){
    int num;
    cout<<"Enter the num to find the factorial: ";
    cin>>num;
    int fact = 1;

    for(int i=1;i<=num;i++){
        fact *= i;
    }

    cout<<"The factorial is: "<<fact;
    return 0;
}
#include<iostream>
using namespace std;

int main(){
    int num;
    cout<<"Enter the num to get the table: ";
    cin>>num;

    for(int i=1;i<=10;i++){
        int mul = num*i;
        cout<<num<<"*"<<i<<"="<<mul<<endl;
    }
    return 0;
}
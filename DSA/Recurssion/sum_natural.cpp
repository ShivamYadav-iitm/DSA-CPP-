#include<iostream>
using namespace std;


int sum(int n){
    if(n==1){   //base case
        return 1; 
    }
    return n + sum(n-1);//work we have to do      //assumption , faith
}
int main(){
    int n=10;
    cout<<sum(n);
    return 0;
}
#include<iostream>
using namespace std;


int fact(int x){
    int fac =1;
    for(int i=1;i<=x;i++){
        
        fac = fac* i;
        
    }
    return fac;
    
}

int bincoeff(int n,int r){
    int val1 = fact(n);
    int val2 = fact(r);
    int val3 = fact(n-r);
    int result = val1/(val2 * val3);
    return result;
}


int main(){
    cout<<bincoeff(4,2);
    return 0;
}
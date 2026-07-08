#include<iostream>
using namespace std;

int sum = 0;
int lastdig;
int digsum(int x){
    
    
    while(x>0){
        lastdig = x%10;
        sum += lastdig;
        x = x/10;
    }
    return sum;
}

int main(){
    digsum(12345);
    cout<<sum;
    return 0;
}
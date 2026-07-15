#include<iostream>
using namespace std;

int countset(int num){
    int count = 0;
    while(num>0){
        int lastdig = num & 1 ; 
        count += lastdig;
        num  = num>>1; 
    }
    return count;
}



int main(){
    int num = 10;
    int val = 2;
    int  i = 2;
    cout<<countset(num);
    return 0;
}
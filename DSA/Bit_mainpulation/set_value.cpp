#include<iostream>
using namespace std;

int setval(int num,int i,int val){
    int bitmask = ~(1<<i); //bitMask to clear ith bit
    num =  num & bitmask; //clear ith bit
    num = num | (val<<i); //changing cleared bit acc to val
    return num;
}

int clearbit(int num, int i){
    int bitMask = ~0<<i; //bitMask to clear i bits from last
    num = num&bitMask; //clear i bits from last
    return num;
}



int main(){
    int num = 15;
    int val = 2;
    int  i = 2;
    //cout<<setval(num,i,val);
    cout<<clearbit(num,i);
    return 0;
}
#include<iostream>
using namespace std;

int main(){
    int n=10289;
    int sum = 0;
    int i;

    while(n>0){
        i = n%10;
        sum =  sum*10 + i;
        n = n/10;
    }
    cout<<sum+1;
    return 0;
}
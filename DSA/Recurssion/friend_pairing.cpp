#include<iostream>
#include<vector>
using namespace std;

int pairing(int n){
    if(n==1){
        return 1;
    }
    else if(n==2){
        return 2; 
    }

    return pairing(n-1) + pairing(n-2)*(n-1);

}
int main(){
    cout<<pairing(4);
    return 0;
}
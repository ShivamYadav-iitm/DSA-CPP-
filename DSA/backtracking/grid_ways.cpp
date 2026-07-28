#include<iostream>
#include<vector>
#include<string>
using namespace std;

int Gridways(int r,int col,int n,int m){
    if(r==n-1 && col == m-1){
        return 1;
    }
    if(r >= n || col >=m){
        return 0;
    }

    //for right
    int val1 = Gridways( r, col+1 , n , m);
    //for down 
    int val2 = Gridways( r+1, col , n , m);

    return val1+val2;

}


int main(){
    int n = 3;
    int m = 3;
    cout<<Gridways(0,0,n,m);
    return 0;
}
#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

//O{n}
int MinCoin(vector<int>coins,int value){ //my method 
    int n = coins.size();
    int total = 0;
    for(int i=n-1;i>=0&&value!=0;i--){
        if(value>=coins[i]){
            total++;
            cout<<"chose "<<coins[i]<<"'s note"<<endl;
            value -= coins[i];
            i = n-1;
        }
    }
    return total;    
}

int MinCoin2(vector<int>coins,int value){//shradha ma'am method
    int n = coins.size();
    int total = 0;
    for(int i=n-1;i>=0&&value!=0;i--){
        if(value>=coins[i]){
            total += value/coins[i];
            
            value = value%coins[i];
            
        }
    }
    return total;    
}

int main(){
    int v = 690;
    vector<int>coins = {1,2,5,10,20,50,100,500,2000};
    cout<<MinCoin2(coins,v)<<endl;
    return 0;
}
#include<iostream>
using namespace std;

void binstr(string ans,int n,int lastplace){
    if(n==0){
        cout<<ans<<endl;
        return;
    }
    if(lastplace != 1){
        binstr(ans+'0',n-1,0);
        binstr(ans+'1',n-1,1);
    }
    else{
        binstr(ans+'0',n-1,0);
    } 
}
int main(){
    string ans = "";
    binstr(ans,6,0);
    return 0;
}
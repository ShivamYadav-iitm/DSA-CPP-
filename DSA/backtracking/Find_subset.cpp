#include<iostream>
#include<string>
using namespace std;

void subs(string str ,string substring){
    int n = str.size();
    if(n==0){          //base case
        cout<<substring<<endl;
        return;
    }
    char ch = str[0];
    subs(str.substr(1,n-1),substring + ch); //yes choice
    subs(str.substr(1,n-1),substring);
}

int main(){
    string str = "abc";
    string substring = "";
    subs(str,substring);
    return 0;
}
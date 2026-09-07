#include<iostream>
#include<map>
#include<string>
using namespace std;

int main(){
    map<int,string> m;

    m[101] = "rahul";
    m[102] = "neha";
    m[103] = "rajat";

    cout<<m[101]<<endl; //replace old value for same key 
    cout<<m.count(105)<<endl; // gives if key is present or not 

    for(auto it:m){
        cout<<"key = " << it.first << ", value = "<<it.second<<endl;
    }
}
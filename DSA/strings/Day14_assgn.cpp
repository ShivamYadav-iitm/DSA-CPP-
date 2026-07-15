#include<iostream>
#include<cstring>
using namespace std;


//-------------------------------------------ques01-------------------------------------------
int smallcount(string str){
    int count=0;
    for(int i=0;i<str.length();i++){
        if(str[i]<97){
            count++;
        }

    }
    return count;
}

//-------------------------------------------ques02-------------------------------------------

bool isequal(string str1,string str2){
    int start =0;
    int end = str2.length()-1;
    while(str1!=str2 && start<end){
    swap(str2[start],str2[end]);
    start ++;
    end--;
    }
}


int main(){
    cout<<"enter the string: ";
    string str1;
    cin>>str1;
    cout<<"enter the string2: ";
    string str2;
    cin>>str2;
    cout<<isequal(str1,str2);
    return 0;
}
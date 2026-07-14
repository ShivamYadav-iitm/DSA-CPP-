#include<iostream>
#include<cstring>
using namespace std;

void upper(char word[],int n){
    for(int i=0;i<n;i++){
        if(word[i]>97){
            word[i] -= 32;
        }
    }
    cout<<word;
}

int main(){
    char word[] = "ApplE";
    int len = strlen(word);
    upper(word,len);
    return 0;
}
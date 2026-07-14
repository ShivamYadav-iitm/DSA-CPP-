#include<iostream>
#include<cstring>
using namespace std;

void reverse(char word[],int n){
    int start = 0;
    int end = n-1;
    while(start<=end){
        swap(word[start],word[end]);
        start++;
        end--;
    }
    cout<<word;
}

int main(){
    char ch[] = {'c','o','d','e'};
    int len = strlen(ch);
    reverse(ch,len);
    return 0;
}
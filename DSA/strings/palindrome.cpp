#include<iostream>
#include<cstring>
using namespace std;

bool ispalindrome(char word[],int n){
    int start = 0;
    int end = n-1;
    while(start<end){
        if(word[start]!=word[end]){
            return false;
        }
        start++;
        end--;
    }
    return true;
    
}

int main(){
    char ch[] = "racecar";
    string str;
    getline(cin,str);
    int len = strlen(ch);
    cout<<ispalindrome(ch,len);
    cout<<str;
    return 0;
}
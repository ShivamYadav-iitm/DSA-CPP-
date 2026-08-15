#include<iostream>
#include<queue>
#include<string>
using namespace std;

void FirstNonRepeating(string str,int n){  //O{n}
    int freq[26] = {0};
    queue<char> Q;
    for(int i=0;i<n;i++){
        char ch = str[i];
        Q.push(ch);
        freq[ch - 'a']++;
        while(!Q.empty()&& freq[Q.front()-'a']>1){
            Q.pop();
        }

        if(Q.empty()){
            cout<<"-1"<<endl;
        }
        else{
            cout<<Q.front()<<endl;
        }
    }
}

int main(){
    string str = "aabccxb";
    int n = str.size();
    FirstNonRepeating(str,n);
    return 0;
}
#include<iostream>
#include<string>
using namespace std;

void removeDup(string str,string ans,int map[26],int i){ 
    char ch = str[i];
    int mapIdx = (int)(ch - 'a');
    if(i == str.size()){
        cout<<ans;
        return;
    }
    else if(map[mapIdx]==false){
            ans += str[i];
            map[mapIdx] = true;
            removeDup(str,ans,map,i+1);
    }
    else{
        removeDup(str,ans,map,i+1);
    }
    
}

int main(){
    string str = "appnnacollege";
    string ans = "";
    int map[26] = {false};
    removeDup(str,ans,map,0);
    return 0;
}
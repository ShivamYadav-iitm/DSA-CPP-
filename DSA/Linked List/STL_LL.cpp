#include<iostream>
#include<list>
#include<iterator>
using namespace std;

void printlist(list<int> ll){   
    list<int>::iterator itr;
    for(itr=ll.begin();itr!=ll.end();itr++){ //ll.begin() gives head pointer && ll.end() gives pointer of tail->next 
        cout<<(*itr)<<"->";
    }
    cout<<"NULL"<<endl;
}

int main(){
    list<int> ll;
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    ll.push_back(4);
    ll.push_back(5);
    printlist(ll);
    cout<<ll.size()<<endl;
    cout<<ll.front()<<endl<<ll.back()<<endl;
    return 0;

}
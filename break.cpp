// #include <iostream>
// using namespace std;

// int main(){
//     int num;
//     cout<<"Enter num: ";
//     cin>>num;
//     while(num%10!=0){
//         cout<<"Enter next num: ";
//         cin>>num;
//     }
//     return 0;
// }

#include <iostream>
using namespace std;

int main(){
    int num;
    do{
        cout<<"Enter number: ";
        cin>>num;
        if(num %10 == 0){
            break;
        }
        cout<<"you entered :"<<num<<"\n";

    }while(true);
}
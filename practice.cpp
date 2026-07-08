#include<iostream>
using namespace std;

//--------------------------------------------------------reverse the number

int main(){
    int n=10289;
    int sum = 0;
    int i;

    while(n>0){
        i = n%10;
        sum =  sum*10 + i;
        n = n/10;
    }
    cout<<sum;
    return 0;
}

//--------------------------------------------------------print triangle of 01

// int main(){
//     int n=5;
//     bool val = true;
//     for(int i=1;i<=n;i++){
//         for(int j=1;j<=i;j++){
//             cout<<val<<" ";
//             val = !val;
//         }
//         cout<<endl;
//     }
// }

//--------------------------------------------------------print rhombus pattern

// int main(){
//     int n=5;
//     for(int i=1;i<=n;i++){
//         for(int j=1;j<=n-i;j++){
//             cout<<" ";
//         }
//         for(int j=1;j<=n;j++){
//             cout<<"*";
//         }
//         cout<<endl;
//     }
// }

//--------------------------------------------------------palindromic pattern with numbers

// int main(){
//     int n=5;
//     for(int i=1;i<=n;i++){
//         for(int j=1;j<=n-i;j++){
//             cout<<" ";
//         }
//         for(int j=i;j>=1;j--){
//             cout<<j;
//         }
//         for(int j=2;j<=i;j++){
//             cout<<j;
//         }
//         cout<<endl;
//     }
// }

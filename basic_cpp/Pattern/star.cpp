#include<iostream>
using namespace std;

//star pattern
class pattern{
    public:
        void star(){
        int n=5;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=i;j++){
                cout<<"*";
            }
            cout<<endl;
        }
        cout<<endl;
    };

        //inverted star
        void instar(){
        int n=5;
        for(int i=1;i<=n;i++){
            for(int j=n;j>=i;j--){
                cout<<"*";
            }
            cout<<endl;
        }
};

};


int main(){
    pattern p;
    p.star();
    p.instar();
    return 0;
}


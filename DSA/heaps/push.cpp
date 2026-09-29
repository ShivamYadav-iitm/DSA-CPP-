#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Heap {
    vector<int> vec; //CBT
public:

    void push(int val){
        vec.push_back(val);
        int childIdx = vec.size()-1;
        int parIdx = (childIdx -1)/2;

        while(parIdx >= 0 && vec[childIdx] > vec[parIdx]){ //fix , O{logN}
            swap(vec[childIdx],vec[parIdx]);
            childIdx = parIdx;
            parIdx = (childIdx - 1)/ 2;
        }
    }

    int top(){ //O{N}
        return vec[0];
    }

    bool empty(){
        return vec.size() == 0;
    }
};

int main(){
    Heap heap;
    heap.push(50);
    heap.push(10);
    heap.push(100);

    cout<<"top = "<<heap.top()<<endl;


}
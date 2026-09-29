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

    void heapify(int parIdx){
        if(parIdx>= vec.size()){ //base case
            return;
        }
    
        int leftIdx = parIdx * 2 + 1;
        int rightIdx = parIdx * 2 + 2;
        int maxIdx = parIdx;

        if(leftIdx < vec.size() && vec[leftIdx] > vec[parIdx]){
            maxIdx = leftIdx;
        }

        if(rightIdx < vec.size() && vec[rightIdx] > vec[parIdx]){
            maxIdx = rightIdx;
        }

        swap(vec[parIdx],vec[maxIdx]);
        if(maxIdx != parIdx){
            heapify(maxIdx);
        }

    }

    void pop(){
        swap(vec[0],vec[vec.size()-1]); // step 1

        vec.pop_back(); //step 2

        heapify(0); //O{logN}
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

    heap.pop();
    cout<<"top = "<<heap.top()<<endl;
    return 0;

}
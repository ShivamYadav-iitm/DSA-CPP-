#include<iostream>
#include<queue>
#include<string>
using namespace std;

class Student{
public: 
    string name;
    int marks;

    Student(string name,int marks){
        this->name = name;
        this->marks = marks;
    }

    bool operator <(const Student &obj) const{ //max heap beacuse "<"
        return this->name < obj.name; //max heap
        }
};

int main(){
    priority_queue<Student>pq;

    pq.push(Student("aman",500));
    pq.push(Student("bhumika",400));
    pq.push(Student("chetan",750));

    while(!pq.empty()){
        cout<<pq.top().name<<","<<pq.top().marks<<endl;
        pq.pop();
    }
    return 0;
}
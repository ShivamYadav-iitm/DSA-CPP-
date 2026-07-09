#include<iostream>
using namespace std;

int main()
{
    int arr[5];
    int n = sizeof(arr)/sizeof(int);

    //to input the values of array:
    for(int i=0;i<n;i++){
        cout<<"Enter the "<<i<<"th value: ";
        cin>>arr[i];
    }
    //to print the values in array: 
    for(int i=0;i<n;i++){
        cout<<"\nThe "<<i<<"th value in the array is: ";
        cout<<arr[i]<<"\n";
    }
    return 0;
}
#include<iostream>
using namespace std;
void insertion(int arr[],int &size,int capacity,int element,int position){
    if (size>=capacity)
    {
        cout<<"Array is full. Cannot insert"<<endl;
        return;
    }
    for (int i = size; i >= position; i--)
    {
        arr[i]=arr[i-1];
    }
    arr[position]=element;
    size++;
}
void display(int arr[],int &size){
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
    
}
int main(){
    int arr[10]={1,2,4,5,6,0,0,0,0,0};
    int size=5,capacity=10,element=3,position=2;
    insertion(arr,size,capacity,element,position);
    display(arr,size);
    return 0;
}
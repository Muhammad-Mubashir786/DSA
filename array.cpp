#include<iostream>
#include<vector>
using namespace std;

int main(){
    string cars[4]={"BMW","Volvo","Mazda","Tesla"};
    cout<<cars[0]<<endl;
    cars[0]="Buggati";
    cout<<cars[0]<<endl;
    for (int i = 0; i < 4; i++)
    {
        cout<<i<<" = "<<cars[i]<<" "<<endl;
    }
    
    int numbers[5]={10,20,30,40,50};
    for (int i = 0; i < 5; i++)
    {
        cout<<i<<" = "<<numbers[i]<<" "<<endl;
    }
    for (int i : numbers) //for-each loop
    {
        cout<<i<<" ";
    }
    cout<<endl;
    for(string i : cars){
        cout<<i<<" ";
    }


    int arr[2];
    arr[0]=1;
    arr[1]=2;

    cout<<"\n";

    vector<string>car = {"Honda","Toyota","Suzuki"};
    car.push_back("Ford");
    for(string i : car){
        cout<<i<<" ";
    }
    cout<<"\n"<<car.size()<<endl;
    cout<<sizeof(numbers)<<endl;
    cout<<sizeof(numbers)/sizeof(numbers[0])<<endl;

    for (int i = 0; i < sizeof(numbers)/sizeof(numbers[0]); i++)
    {
        cout<<numbers[i]<<" ";
    }
    
       
    return 0;
}
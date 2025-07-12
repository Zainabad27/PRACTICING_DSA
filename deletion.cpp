#include<iostream>
using namespace std;
void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << endl;
    }
}

void deletion(int arr[],int index,int size){

    for(int i=index;i<size;i++){
        arr[i]=arr[i+1];
    }
}
int main(){
    int arr[10]={1,2,3,4,5,6,7,8,9,10};
    deletion(arr,4,10);
    display(arr,10-1);
    return 0;
}
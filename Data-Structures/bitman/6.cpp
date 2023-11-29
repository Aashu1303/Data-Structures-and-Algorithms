#include<iostream>
using namespace std;

int setBit(int n , int pos){
    return ((n & (1<<pos)) != 0);
}


void uniquenumber2(int arr[] , int n){
    int xorsum = 0;
 
    for (int i = 0; i < n; i++)
    {
        xorsum ^= arr[i];
    }
    int tempxor = xorsum;
    int setbit = 0;
    int pos = 0;

    while (setbit!=1)
    {
        setbit = xorsum & 1;            // returns 0 or 1 as a bitwise operator is used
        pos++;
        xorsum = xorsum >> 1;
    }
    
    int newxor = 0;

    for (int i = 0; i < n; i++)
    {
        if (setBit(arr[i],(pos-1)))
        {
            newxor ^= arr[i];
        }
        
    }


    cout << newxor << endl;
    cout << (tempxor ^ newxor) << endl;

}


int main(){
    int arr[8] = {1,2,3,1,3,2,7,5};
    uniquenumber2(arr , 8);

    return 0;
}
#include<iostream>
using namespace std;

int uniquenumber(int arr[] , int n){
    int xorsum = 0;
    for (int i = 0; i < n; i++)
    {
        xorsum ^= arr[i];
    }
    return xorsum;
}


int main(){
    int arr[7] = {1,2,3,4,3,1,2};
    cout << uniquenumber(arr , 7) << endl;
}
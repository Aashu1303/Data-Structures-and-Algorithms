#include<iostream>
using namespace std;
 
int getBit(int arr , int n){
    return((arr & (1<<n)) != 0);
}

int setBit(int set , int n){
    return (set | (1<<n));
}

int uniquenumber3(int arr[] , int n){

    int result = 0;

    for(int i = 0; i< 64;i++){             //iterate in the positions of the binary places
        int sum = 0;
            for(int j = 0; j < n ; j++){       // iterate in the array
                if (getBit(arr[j],i))
                {
                    sum++;
                }
            }
        if (sum % 3 != 0)
        {
            result = setBit(result , i);   //mistake ki thi ki result ko equal nhii kia setbit ke
        }
    }
    return result;
}

int main(){
    int arr[10] =  {2,2,3,2,3,4,6,3,6,6};
    cout << uniquenumber3(arr , 10) << endl;
}
 
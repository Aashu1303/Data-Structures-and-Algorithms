#include <iostream>
#include <bitset>

using namespace std;

int getBit(int n , int pos){
    int a = 1 << pos;
    return ((n & a) != 0); //return the condition which we can take as bit which is at that place
}

int setBit(int n , int pos){
    int a = 1 << pos;
    return ((n | a)); //returns decimal number which we get after setting the bit
}

int clearBit(int n , int pos){
    int a = 1 << pos;  //mask
    return (n & (~a));
}

int updateBit(int n , int pos , int value){
    int a = 1 << pos;
    n = n & (~a); // storing the value of n with the clear with at the required position
    return(n | (value << pos));
}

int main() {
    // unsigned short short1 = 5;
    // bitset<16> bitset1{short1};   // the bitset representation of 5
    // cout << bitset1 << endl;  // 0b00000000'00001001

    // unsigned short short2 = short1 << 1;     // 5 left-shifted by 1 = 18 or 19
    // bitset<16> bitset2{short2};
    // cout << bitset2 << endl;  // 0b00000000'00010010 or 0b00000000'00010011 
    
    cout << getBit(5,3) << endl;
    cout << setBit(5,1) << endl;
    cout << clearBit(5,2) << endl;
    cout << updateBit(5,3,1) << endl;

    return 0;
}
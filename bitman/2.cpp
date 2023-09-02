#include<iostream>
using namespace std;

int check(int n){
    if (n == 0)      //boundary conditions
    {
        return 0;
    }
    else
    return((n & (n-1)) == 0);
}

int main(){
    
    int m; cin >> m ;
    cout << check(m) << endl;
    if (check(m) == 1)
    {
        cout << "Yes it is a multiple of 2 ";
    }
    
    else{
        cout << "No this number is not a multiple of 2";
    }
    
    return 0;
}
#include<iostream>

using namespace std;

class Stack{
    public:
        int size;
        int top;
        int *arr;

    Stack(int size){
        this -> size = size;
        arr = new int[size];  // allocating new memory for arr of size (size)
        top = -1;
    }

    void push(int data){
        if (size - top < 1)
        {
            cout << "Stack Overflow" << endl;
        }

        else{
            top ++;
            arr[top] = data;
        }
    }

    void pop(){
        if (top == -1)
        {
            cout << "Stack is Underflow" << endl;
        }

        else{
            top--;
        }
    }

    int peek(){
        if (top == -1)
        {
            cout << "Stack is empty" << endl;
            return -1;
        }

        else{
            return arr[top];
        }
        
    }

    bool isEmpty(){
        if (top == -1)
        {
            return true;
        }
        else{
            return false;
        }
    }

};


int main(){

    Stack s(5);
    s.push(54);
    cout << s.peek();

    return 0;
}
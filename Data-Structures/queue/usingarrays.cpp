#include <iostream>
#include <climits>

using namespace std;

class Queue
{
    int front, rear, s;
    int *arr;

public:
    Queue()
    {
        s = 100001;
        arr = new int[s];
        front = 0, rear = 0;
    }

    int top()
    {
        if (isEmpty())
        {
            return -1;
        }
        return arr[front];
    }

    void push(int val)
    {
        if (rear == s)
        {
            cout << "Queue is Full my Boy!" << endl;
            return;
        }
        arr[rear] = val;
        rear++;
    }

    bool isEmpty()
    {
        if (rear == front)
        {
            return true;
        }
        return false;
    }

    int size()
    {
        return (rear - front);
    }

    int pop()
    {
        if (isEmpty())
        {
            return -1;
        }
        int temp = arr[front];
        front++;
        if (front == rear)
        {
            front = 0;
            rear = 0;
        }
        return temp;
    }
};

int main()
{
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    // To check whether queue full functionality working or not
    //  for(int i = 0 ; i < 100002 ; i++){
    //      q.push(i);
    //  }

    cout << "Size of Queue: " << q.size() << endl;

    // Traversing in Queue
    while (!q.isEmpty())
    {
        cout << q.top() << endl;
        q.pop();
    }
    return 0;
}
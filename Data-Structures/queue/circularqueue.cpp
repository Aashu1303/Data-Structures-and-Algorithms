#include <iostream>
using namespace std;

class CircularQueue
{
private:
    int *arr;
    int size;
    int head;
    int tail;

public:
    CircularQueue(int k)
    {
        arr = new int[k];
        head = -1;
        tail = -1;
        size = k;
    }

    bool enQueue(int val)
    {
        if (isFull())
        {
            cout << "Circular Queue is Full!";
            return false;
        }
        if (isEmpty())
        {
            head = 0;
        }

        /**Let's say tail = -1 and size = 4. tail = (0) % 4 => tail = 0.
         * and if tail = 3 (since indexing is from 0, it means tail reaches the end)
         * tail = (4) % 4 => tail = 0; which means tail is now at starting **/
        tail = (tail + 1) % size;
        arr[tail] = val;
        return true;
    }

    bool deQueue()
    {
        if (isEmpty())
        {
            return false;
        }

        /**head == 4 == tail it means that this is the only element present there
         * so, after deleting it the queue will be empty and the condition for this is
         * head == tail == -1
         **/
        if (head == tail)
        {
            head == -1;
            tail == -1;
            return true;
        }

        head = (head + 1) % size;
        return true;
    }

    int front()
    {
        if (isEmpty())
        {
            return -1;
        }
        return arr[head];
    }

    int rear()
    {
        if (isEmpty())
        {
            return -1;
        }
        return arr[tail];
    }

    bool isEmpty()
    {
        return (head == -1);
    }

    bool isFull()
    {
        if ((tail + 1) % size == head)
        {
            return true;
        }
        return false;
    }
};

int main()
{
    CircularQueue q(4);

    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);
    q.enQueue(4);

    cout << q.rear() << endl;
    q.deQueue();
    cout << q.front() << endl;
    q.enQueue(5);
    cout << q.rear() << endl;

    cout << "Is Queue Empty? ";
    if (q.isEmpty())
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }

    return 0;
}
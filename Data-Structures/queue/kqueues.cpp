// Creating K queues using a single array (Love Babbar)
#include <iostream>
using namespace std;

class kQueue
{

private:
    int n;
    int k;
    int *front;
    int *rear;
    int *arr;
    int freeSpot;
    int *next; // to store next free spaces for that particular index in the main array

public:
    kQueue(int n, int k)
    {
        this->n = n;
        this->k = k;
        front = new int[k];
        rear = new int[k];
        arr = new int[n];
        for (size_t i = 0; i < k; i++)
        {
            front[i] = -1;
            rear[i] = -1;
        }

        next = new int[n];

        for (size_t i = 0; i < n; i++)
        {
            if (i == n - 1)
                next[i] = -1;
            else
                next[i] = i + 1;
        }
        freeSpot = 0;
        arr = new int[n];
    }

    void enQueue(int data, int qn)
    {
        // check overflow condition
        if (freeSpot == -1)
        {
            cout << "Array is Full" << endl;
            return;
        }
        // find first free index
        int index = freeSpot;
        // update freeSpot
        freeSpot = next[index];

        // check whether the number is the first element of the queue or not
        if (front[qn - 1] == -1)
        {
            front[qn - 1] = index;
        }
        else
        {
            // linking new element to the previous one
            next[rear[qn - 1]] = index;
        }

        // insert element at that index
        arr[index] = data;

        // Since this index is already full
        next[index] = -1;

        // Update rear
        rear[qn - 1] = index;
    }

    int deQueue(int qn)
    {
        // underflow condition
        if (front[qn - 1] == -1)
        {
            cout << "Queue is already empty" << endl;
            return -1;
        }
        int index = front[qn - 1];
        front[qn - 1] = next[front[qn - 1]];
        next[index] = freeSpot;
        freeSpot = index;

        return arr[index];
    }

    int top(int qn)
    {
        if (front[qn - 1] == -1)
        {
            cout << "Queue is Empty" << endl;
            return -1;
        }
        return arr[front[qn - 1]];
    }

    int back(int qn)
    {
        if (rear[qn - 1] == -1)
        {
            cout << "Queue is Empty" << endl;
            return -1;
        }
        int temp = rear[qn - 1];
        return arr[temp];
    }
};

int main()
{

    kQueue q(5, 2);
    q.enQueue(1,1);
    q.enQueue(2,1);
    q.enQueue(3,1);
    q.enQueue(4,1);
    q.enQueue(1,2);

    cout << q.deQueue(1) << endl;
    cout << q.deQueue(2) << endl;
    cout << q.deQueue(1) << endl;
    return 0;
}
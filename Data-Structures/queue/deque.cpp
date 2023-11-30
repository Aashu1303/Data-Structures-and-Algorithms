#include <iostream>
#include <vector>

using namespace std;

class MyCircularDeque
{
    int size;
    int head;
    int tail;
    vector<int> v;

public:
    MyCircularDeque(int k)
    {
        head = -1;
        tail = -1;
        v.resize(k);
        size = k;
    }

    bool insertFront(int value)
    {
        if (isFull())
        {
            return false;
        }
        if (isEmpty())
        {
            head = size;
            tail = size - 1;
        }
        if (head == 0)
        {
            head = size;
        }
        head--;
        v[head] = value;
        return true;
    }

    bool insertLast(int value)
    {
        if (isFull())
        {
            return false;
        }
        if (isEmpty())
        {
            tail = -1;
            head = 0;
        }
        if (tail == (size - 1))
        {
            tail = -1;
        }
        tail++;
        v[tail] = value;
        return true;
    }

    bool deleteFront()
    {
        if (isEmpty())
        {
            return false;
        }
        if (head == tail)
        {
            head = -1;
            tail = -1;
            return true;
        }
        head++;
        if (head == size)
        {
            if (tail == -1)
            {
                head = -1;
            }
            head = 0;
        }
        return true;
    }

    bool deleteLast()
    {
        if (isEmpty())
        {
            return false;
        }
        if (head == tail)
        {
            head = -1;
            tail = -1;
            return true;
        }
        tail--;
        if (tail == -1)
        {
            if (head > 0)
            {
                tail = -1;
            }
            tail = size - 1;
        }
        return true;
    }

    int getFront()
    {
        if (isEmpty())
        {
            return -1;
        }
        if (head == -1)
        {
            return v[0];
        }
        return v[head];
    }

    int getRear()
    {
        if (isEmpty())
        {
            return -1;
        }
        if (tail == -1)
        {
            return v[size - 1];
        }
        return v[tail];
    }

    bool isEmpty()
    {
        return (head == -1 && tail == -1);
    }

    bool isFull()
    {
        return ((tail + 1) % size == head);
    }
};

int main()
{

    MyCircularDeque *obj = new MyCircularDeque(8);
    bool param_1 = obj->insertFront(5);
    int x = obj->getFront();
    bool param_8 = obj->deleteLast();
    // bool param_2 = obj->insertLast(2);
    // bool param_4 = obj->insertFront(3);
    // bool param_5 = obj->insertFront(4);
    // int param_6 = obj->getRear();
    // bool param_7 = obj->isFull();
    // bool param_9 = obj->insertFront(4);
    // int param_10 = obj->getFront();

    return 0;
}
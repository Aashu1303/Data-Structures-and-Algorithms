#include <iostream>
#include <queue>
using namespace std;

// push :- push elements in rear i.e. pushing elements from back
// pop :- popping elements from front i.e. popping elements from top
// size :- Returns size of the queue
// isEmpty :- Returns boolean value stating whether stack is empty or not
// front() :- Returns the top element of the queue

int main()
{

    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);

    // Obviously finding size
    cout << "Size of Queue: " << q.size() << endl;

    // Traversing in Queue
    while (!q.empty())
    {
        cout << q.front() << endl;
        q.pop();
    }

    return 0;
}

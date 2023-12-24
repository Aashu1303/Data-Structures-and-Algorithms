#include <iostream>
#include <deque>

using namespace std;

int main()
{
    int n;
    cin >> n;
    if (n <= 3)
    {
        if(n == 1) cout << 1 << endl;
        else cout << "NO SOLUTION" << endl;
    }
    if(n == 4){
        cout << "2 4 1 3" << endl;
    }
    else
    {
        deque<int> dq;
        for (int i = 0; i <= n; i += 2)
        {
            if (i % 2 == 0 && i != 0)
                dq.push_front(i);
        }

        for (int i = n; i >= 1; i--)
        {
            if (i % 2 != 0)
                dq.push_back(i);
        }

        while (!dq.empty())
        {
            cout << dq.front() << " ";
            dq.pop_front();
        }
    }
}
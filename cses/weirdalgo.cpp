#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio();
    cin.tie(0);

    int n;
    cin >> n;
    do
    {
        cout << n << " ";
        if (n % 2)
        {
            n = (n * 3) + 1;
        }
        else
        {
            n = n / 2;
        }
    } while (n != 1);
    cout << n;
    return 0;
}
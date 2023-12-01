#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define ll long long int

inline int nxt()
{
    int x;
    cin >> x;
    return x;
}

void solve() {}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    ll count = 0;
    int temp;
    while (cin >> temp)
    {
        count += temp;
    }

    ll sum = (n * (n + 1)) / 2;

    cout << sum - count;

    return 0;
}
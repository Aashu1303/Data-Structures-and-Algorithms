#include <bits/stdc++.h>
using namespace std;

// Macros
#define int long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define rrep(i, a, b) for (int i = (b)-1; i >= (a); --i)
#define endl '\n'

// Typedefs
typedef vector<int> vi;
typedef pair<int, int> pii;

// Constants
const int INF = LLONG_MAX;
const int MOD = 1e9 + 7;

// Utility functions
template <typename T>
T gcd(T a, T b) { return b == 0 ? a : gcd(b, a % b); }
template <typename T>
T lcm(T a, T b) { return a / gcd(a, b) * b; }
template <typename T>
T modpow(T base, T exp, T mod)
{
    T result = 1;
    while (exp > 0)
    {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

int solve(int n, vi v)
{
    if (n == 1)
    {
        return 0;
    }
    int prev = v[0];
    int ans = 0;
    rep(i, 1, n)
    {
        if (v[i] < prev)
        {
            ans += abs(v[i] - prev);
            v[i] = prev;
        }
        prev = v[i];
    }
    return ans;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    int temp;
    vi v;
    while (cin >> temp)
    {
        v.push_back(temp);
    }
    cout << solve(n, v);
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

//CODED BY SUMIT KUMAR PRAJAPATI
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;

#define si(x) scanf("%d", &x)
#define sl(x) scanf("%lld", &x)
#define ss(s) scanf("%s", s)
#define pi(x) printf("%d\n", x)
#define pl(x) printf("%lld\n", x)
#define ps(s) printf("%s\n", s)
#define PI 3.1415926535897932384626
#define pb push_back
#define mk make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define rep(i, n) for (ll i = 0; i < n; i++)
#define repe(i, n) for (ll i = 1; i <= n; i++)
#define FOR(i, a, b) for (ll i = a; i <= b; i++)
#define curtime chrono::high_resolution_clock::now()
#define timedif(start, end) chrono::duration_cast<chrono::nanoseconds>(end - start).count()
const int MX = 1e5 + 5;
const int MD = 1e9 + 7;
const int MDL = 99824453;
auto time0 = curtime;
bitset<MX> isPrime;
vector<ll> poss;

void init()
{
    isPrime = ~isPrime;
    isPrime[1] = false;
    for (ll i = 2; i * i <= MX; i++)
    {
        if (isPrime[i])
        {
            for (ll j = i * i; j < MX; j += i)
                isPrime[j] = false;
        }
    }
    for (ll i = 2; i < MX; i++)
        if (isPrime[i])
            poss.push_back(i * i);
}

ll binary(ll key)
{
    ll l = 0, r = poss.size() - 1;
    ll mid, ans = 0;
    while (l <= r)
    {
        mid = (l + r) / 2;
        if (poss[mid] <= key)
        {
            ans = max(ans, mid);
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    return ans;
}
ll binary2(ll key)
{
    ll l = 0, r = poss.size() - 1;
    ll mid, ans = r;
    while (l <= r)
    {
        mid = (l + r) / 2;
        if (poss[mid] > key)
        {
            ans = min(ans, mid);
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    return ans;
}

void solve()
{

    ll n, k;
    cin >> n >> k;

    ll choices = binary(n), gf = binary2(k);
    if (gf > choices)
    {
        gf = 0;
    }
    else
    {
        gf = choices + 1 - gf;
    }
    cout << choices + 1 << " " << gf << '\n';
}

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif

    srand(time(0));

    time0 = curtime;
    ll t = 1;
    cin >> t;
    init();
    while (t--)
        solve();

    return 0;
}

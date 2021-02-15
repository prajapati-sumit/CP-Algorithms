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
#define rep(i, n) for (int i = 0; i < n; i++)
#define repe(i, n) for (int i = 1; i <= n; i++)
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define curtime chrono::high_resolution_clock::now()
#define timedif(start, end) chrono::duration_cast<chrono::nanoseconds>(end - start).count()
const int MX = 5300000;
const int MD = 1e9 + 7;
const int INF = 1e7 + 6e5;
auto time0 = curtime;

vector<int> isPrime(MX, 0);
vector<int> primes;
vector<int> res;
int b[INF];

void solve()
{

    int k;
    cin >> k;
    int ans = res[k - 1];
    cout << ans << "\n";
}
void init()
{

    for (int i = 2; i * i <= MX; i++)
    {
        if (!isPrime[i])
        {
            for (int j = i * i; j < MX; j += i)
                isPrime[j] = true;
        }
    }
    for (int i = 2; i < MX; i++)
        if (!isPrime[i])
            primes.push_back(i);

    auto itr = primes.begin();
    for (; itr != primes.end(); itr++)
    {
        int cur = *itr;
        for (int j = cur << 1; j < INF; j += cur)
        {
            if (!isPrime[j / cur])
                b[j]++;
        }
    }
    rep(i, INF) if (b[i] == 2)
        res.push_back(i);
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
    int t = 1;
    cin >> t;

    init();
    while (t--)
    {
        solve();
    }
    cerr << "Ex Time: " << timedif(time0, curtime) * 1e-9 << " sec\n";
    return 0;
}

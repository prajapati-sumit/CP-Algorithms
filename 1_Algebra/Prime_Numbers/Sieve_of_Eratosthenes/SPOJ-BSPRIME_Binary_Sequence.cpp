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
const int MX = 1e6+2;
const int MD = 1e9 + 7;
const int MDL = 99824453;
auto time0 = curtime;

vector<bool> isPrime(MX, true);
vector<int> primes;
vector<int> ones;
vector<int> lengths;

int binary(int x)
{
    int l = 0, r = primes.size(), mid;
    int ans = 0;
    while (l <= r)
    {   
        //cout<<mid<<" "<<lengths[mid]<<" "<<x<<'\n';
        mid = (l + r)>>1;
        if (lengths[mid] <= x)
        {
            ans = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    return ans;
}

void solve()
{

    int n;
    cin >> n;
    if(n==0){
        cout<<"0\n";
        return;
    }
    //Can't Optimise 
    int indx = binary(n), ans = 0;
    ans = ones[indx];
    
    n -= lengths[indx];
    if (n != 0)
    {
        indx++;
        ans += __builtin_popcount(primes[indx] >> (lengths[indx]-lengths[indx-1] - n));
    }
    cout << ans << '\n';
}
void init()
{

    for (int i = 2; i * i <= MX; i++)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j < MX; j += i)
                isPrime[j] = false;
        }
    }
    int ones_b = 0, length_b = 0;
    for (int i = 2; i < MX; i++)
        if (isPrime[i])
        {
            int one = 0, sz = 0, temp = i;
            while (temp)
            {
                if (temp & 1)
                    one++;
                sz++;
                temp >>= 1;
                
            }

            primes.emplace_back(i);
            ones.emplace_back(one + ones_b);
            lengths.emplace_back(sz + length_b);
            ones_b = one + ones_b;
            length_b = sz + length_b;
        }
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
    //cout<<primes.back()<<" "<<lengths.back()<<'\n';
    while (t--)
        solve();

    cerr<<"Ex Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;
}

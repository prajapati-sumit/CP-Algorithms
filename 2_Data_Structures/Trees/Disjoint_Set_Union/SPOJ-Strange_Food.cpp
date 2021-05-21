// AUTHOR: Sumit Prajapati
#include <bits/stdc++.h>
using namespace std;


#define ull                 unsigned long long
#define ll                  long long
#define pii                 pair<int, int>
#define pll                 pair<ll, ll>
#define pb                  push_back
#define mk                  make_pair
#define ff                  first
#define ss                  second
#define all(a)              a.begin(),a.end()
#define trav(x,v)           for(auto &x:v)
#define debug(x)            cerr<<#x<<" = "<<x<<'\n'
#define llrand()            distribution(generator)
#define rep(i,n)            for(int i=0;i<n;i++)
#define repe(i,n)           for(int i=1;i<=n;i++)
#define FOR(i,a,b)          for(int i=a;i<=b;i++)
#define printar(a,s,e)      FOR(i,s,e)cout<<a[i]<<" ";cout<<'\n'
#define endl                '\n'
#define curtime             chrono::high_resolution_clock::now()
#define timedif(start,end)  chrono::duration_cast<chrono::nanoseconds>(end - start).count()
#define INF                 1'000'000'000
#define MD                  1'000'000'007
#define MDL                 998244353
#define MX                  50000


auto time0 = curtime;
random_device rd;
default_random_engine generator(rd());
uniform_int_distribution<ull> distribution(0, 0xFFFFFFFFFFFFFFFF);

//Is testcase present?

vector<pii>parent;
void fastscan(int &x)
{
    cin >> x;
    return ;
    bool neg = false;
    int c;
    x = 0;
    c = getchar();
    if (c == '-')
    {
        neg = true;
        c = getchar();
    }
    for (; (c > 47 && c < 58); c = getchar())
        x = (x << 1) + (x << 3) + c - 48;
    if (neg)
        x *= -1;
}
pii find_set(int x) {
    if (parent[x].ff == x) {
        assert(parent[x].ss == 0);
        return parent[x];
    }
    pii anc = find_set(parent[x].ff);
    parent[x].ff = anc.ff;
    parent[x].ss = (parent[x].ss + anc.ss) % 3;
    return parent[x];
}


void solve() {

    //FASTSCAN DONT USE IN SPOJ.
    int n, k;
    fastscan(n);
    fastscan(k);
    parent.clear();
    rep(i, n + 1)
    parent.pb({i, 0});
    int ans = 0;
    repe(i, k) {
        int type, x, y;
        fastscan(type); fastscan(x); fastscan(y);

        if (x > n || y > n) {
            ans++;
            continue;
        }
        pii p_x = find_set(x), p_y = find_set(y);

        // if (p_x.ff == p_y.ff) {
        //     int rxy = (p_x.ss - p_y.ss + 3) % 3;

        //     if (type == 1 && rxy != 0)
        //         ans++;
        //     else if (type == 2 && rxy != 1)
        //         ans++;

        // }
        // else {
        //     // R(r, s) = R(u, v) - R(u, r) + R(v, s)
        //     int r = (type - 1 - p_x.ss + p_y.ss) % 3;
        //     parent[p_x.ff] = {p_y.ff, r };
        // }
        if (type == 1) {

            if (p_x.ff == p_y.ff && p_x.ss != p_y.ss)
                ans++;
            else if (p_x.ff != p_y.ff) {
                int r = (p_x.ss - p_y.ss + 3) % 3;
                parent[p_y.ff] = {p_x.ff, r};
            }

        }
        else {
            bool flag = (p_x.ss - p_y.ss + 3) % 3 == 1;
            if (p_x.ff == p_y.ff && !flag)
                ans++;
            else if (p_x.ff != p_y.ff) {
                int r;
                if (p_x.ss == 0)
                    r = (p_y.ss + 1) % 3;
                if (p_x.ss == 1)
                    r = p_y.ss;
                if (p_x.ss == 2)
                    r = (p_y.ss + 2) % 3;
                parent[p_x.ff] = {p_y.ff, r};
            }
        }
        // repe(i, n)
        // cerr << i << ": [" << parent[i].ff << " " << parent[i].ss << " ] ";
        // cerr << '\n';

    }
    cout << ans << '\n';
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    time0 = curtime;

    int t = 1;
    fastscan(t);
    repe(tt, t) {
        //cout<<"Case #"<<tt<<": ";
        solve();
    }

    //cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;

}
//~ author      : Sumit Prajapati
#include <bits/stdc++.h>
using namespace std;


#define ull                 unsigned long long
#define ll                  long long
#define int                 long long
#define pii                 pair<int, int>
#define pll                 pair<ll, ll>
#define pb                  push_back
#define mk                  make_pair
#define ff                  first
#define ss                  second
#define all(a)              a.begin(),a.end()
#define trav(x,v)           for(auto &x:v)
#define rep(i,n)            for(int i=0;i<n;i++)
#define repe(i,n)           for(int i=1;i<=n;i++)
#define read(a,n)           rep(i,n)cin>>a[i]
#define reade(a,n)          repe(i,n)cin>>a[i]
#define FOR(i,a,b)          for(int i=a;i<=b;i++)
#define printar(a,s,e)      FOR(i,s,e)cout<<a[i]<<" ";cout<<'\n'
#define curtime             chrono::high_resolution_clock::now()
#define timedif(start,end)  chrono::duration_cast<chrono::nanoseconds>(end - start).count()




auto time0 = curtime;
const int MD = 1e9 + 9;
const int MDL = 998244353;
const int INF = 1e9;
const int MX = 3e5 + 5;

int fib[MX];
int n;
int a[MX];
int segm[4 * MX];
pii lazy[4 * MX];

int rangeFib(int l, int r, int f1, int f2) {
    // sec=1*1+1*1=2 fir=1*1
    int sec = (fib[r] * f1 % MD + fib[r + 1] * f2 % MD) % MD;
    int fir = (fib[l - 1] * f1 % MD + fib[l] * f2 % MD) % MD;
    // if(l==1 && r==1 && f1==1 && f2==1)
    //     cout<<sec<<" "<<fir<<'\n';
    return (sec - fir + MD) % MD;
}

void buildtree(int cur, int start, int end) {
    if (start == end) {
        //BASE CASE
        segm[cur] = a[start];
        return;
    }
    int mid = (start + end) >> 1;
    buildtree(cur << 1, start, mid);
    buildtree((cur << 1) + 1, mid + 1, end);
    //MERGING STEP
    segm[cur] = (segm[2 * cur] + segm[2 * cur + 1]) % MD;
}
int f(int p, int f1, int f2) {
    if (p == 1)
        return f1;
    if (p == 2)
        return f2;

    return (fib[p - 2] * f1 % MD + fib[p - 1] * f2 % MD) % MD;
}
int query(int cur, int start, int end, int qs, int qe) {
    int mid = (start + end) >> 1;
    if (lazy[cur].ff != 0 || lazy[cur].ss != 0) {
        auto el = lazy[cur];

        int dx = rangeFib(1, end - start + 1, el.ff, el.ss);
        segm[cur] = (segm[cur] + dx) % MD;
        if (start != end) {

            lazy[2 * cur].ff = (lazy[2 * cur].ff + el.ff) % MD;
            lazy[2 * cur].ss = (lazy[2 * cur].ss + el.ss) % MD;
            lazy[2 * cur + 1].ff = (lazy[2 * cur + 1].ff + f(mid - start + 2, el.ff, el.ss)) % MD;
            lazy[2 * cur + 1].ss = (lazy[2 * cur + 1].ss + f(mid - start + 3, el.ff, el.ss)) % MD;
            // lazy[2 * cur + 1];
        }

        lazy[cur] = {0, 0};
    }
    if (start >= qs && end <= qe) {

        return segm[cur];
    }
    if (start > qe || end < qs)
        return 0;          //INVALID RETURN
    int A = query(2 * cur, start, mid, qs, qe);
    int B = query(2 * cur + 1, mid + 1, end, qs, qe);
    //MERGING STEP
    int res = (A + B) % MD;

    return res;
}
void update(int cur, int start, int end, int qs, int qe) {

    int mid = (start + end) >> 1;
    if (lazy[cur].ff != 0 || lazy[cur].ss != 0) {
        auto el = lazy[cur];
        int dx = rangeFib(1, end - start + 1, el.ff, el.ss);
        segm[cur] = (segm[cur] + dx) % MD;
        if (start != end) {

            lazy[2 * cur].ff = (lazy[2 * cur].ff + el.ff) % MD;
            lazy[2 * cur].ss = (lazy[2 * cur].ss + el.ss) % MD;

            lazy[2 * cur + 1].ff = (lazy[2 * cur + 1].ff + f(mid - start + 2, el.ff, el.ss)) % MD;
            lazy[2 * cur + 1].ss = (lazy[2 * cur + 1].ss + f(mid - start + 3, el.ff, el.ss)) % MD;
            // lazy[2 * cur + 1];
        }

        lazy[cur] = {0, 0};
    }
    if (start >= qs && end <= qe) {
        pii el;
        el.ff = f(start - qs + 1, 1, 1);
        el.ss = f(start - qs + 2, 1, 1);
        int dx = rangeFib(1, end - start + 1, el.ff, el.ss);
        segm[cur] = (segm[cur] + dx) % MD;
        if (start != end) {

            lazy[2 * cur].ff = (lazy[2 * cur].ff + el.ff) % MD;
            lazy[2 * cur].ss = (lazy[2 * cur].ss + el.ss) % MD;
            lazy[2 * cur + 1].ff = (lazy[2 * cur + 1].ff + f(mid - start + 2, el.ff, el.ss)) % MD;
            lazy[2 * cur + 1].ss = (lazy[2 * cur + 1].ss + f(mid - start + 3, el.ff, el.ss)) % MD;
            // lazy[2 * cur + 1];
        }
        return ;
    }
    if (start > qe || end < qs)
        return ;                //OUT OF RANGE
    update(cur << 1, start, mid, qs, qe);
    update((cur << 1) ^ 1, mid + 1, end, qs, qe);
    //MERGING STEP
    segm[cur] = (segm[2 * cur] + segm[2 * cur + 1]) % MD;
}


void solve() {

    int q;
    cin >> n >> q;
    repe(i, n)
    cin >> a[i];
    buildtree(1, 1, n);
    // FINALLY
    repe(i, q) {
        int t, l, r;
        cin >> t >> l >> r;
        if (t == 1) {
            update(1, 1, n, l, r);
        }
        else {
            // repe(i, n)
            //     cout<<query(1,1,n,i,i)<<"\t";
            // cout<<'\n';
            int ans = query(1, 1, n, l, r);
            cout << ans << '\n';
        }
    }


}


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    time0 = curtime;
    srand(time(NULL));
    int t = 1;
    // cin>>t;
    fib[1] = 1;
    fib[2] = 1;
    FOR(i, 3, MX - 1)
    fib[i] = (fib[i - 1] + fib[i - 2]) % MD;
    repe(tt, t) {
        // cout<<"Case #"<<tt<<": ";
        solve();
    }

    // cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;

}
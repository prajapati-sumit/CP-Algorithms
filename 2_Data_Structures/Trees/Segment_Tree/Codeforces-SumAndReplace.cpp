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
const int MD = 1e9 + 7;
const int MDL = 998244353;
const int INF = 1e9;
const int MX = 3e5 + 5;
const int nax = 1e6 + 1;

int n_div[nax + 1];
pii segm[4 * MX];
int a[MX];
int n, q;

void merge(pii &A, pii &B, pii &res) {
    res.ff = A.ff + B.ff;
    res.ss = max(A.ss, B.ss);
}
void buildtree(int cur, int start, int end) {
    if (start == end) {
        //BASE CASE
        segm[cur] = {a[start], a[start]};
        return;
    }
    int mid = (start + end) >> 1;
    buildtree(cur << 1, start, mid);
    buildtree((cur << 1) + 1, mid + 1, end);
    //MERGING STEP
    merge(segm[2 * cur], segm[2 * cur + 1], segm[cur]);

}
pii query(int cur, int start, int end, int qs, int qe) {
    if (start >= qs && end <= qe)
        return segm[cur];
    if (start > qe || end < qs)
        return {0, 0};         //INVALID RETURN
    int mid = (start + end) >> 1;
    pii A = query(2 * cur, start, mid, qs, qe);
    pii B = query(2 * cur + 1, mid + 1, end, qs, qe);
    //MERGING STEP
    pii res;
    merge(A, B, res);

    return res;
}
void update(int cur, int start, int end, int qs, int qe) {

    if (start > qe || end < qs)
        return;          //OUT OF RANGE
    
    if (start == end  ) {
        //DO UPDATE
        a[start] = n_div[a[start]];
        segm[cur] = {a[start], a[start]};
        return;
        
    }
    int mid = (start + end) >> 1;

    if(segm[2*cur].ss > 2)
        update(cur << 1, start, mid, qs, qe);

    if(segm[2*cur+1].ss > 2)
        update((cur << 1) ^ 1, mid + 1, end, qs, qe);

    //MERGING STEP
    merge(segm[2 * cur], segm[2 * cur + 1], segm[cur]);

}

void solve() {

    cin >> n >> q;
    repe(i, n)
    cin >> a[i];
    buildtree(1, 1, n);
    repe(i, q) {
        int ty, l, r;
        cin >> ty >> l >> r;
        if (ty == 1) {
            update(1, 1, n, l, r);
        }
        else {
            cout << query(1, 1, n, l, r).ff << '\n';
        }
    }



}


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for (int i = 1; i <= nax; i++)
        for (int j = i; j <= nax; j += i)
            n_div[j]++;

    time0 = curtime;
    srand(time(NULL));
    int t = 1;
    // cin>>t;
    repe(tt, t) {
        // cout<<"Case #"<<tt<<": ";
        solve();
    }

    // cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;

}
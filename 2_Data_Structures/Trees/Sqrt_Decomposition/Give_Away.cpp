//~ author      : Sumit Prajapati
#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
  
  
#define ull                 unsigned long long
#define ll                  long long
// #define int                 long long
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


#define ordered_set tree<pii, null_type,less<pii>, rb_tree_tag,tree_order_statistics_node_update>


auto time0 = curtime;
const int MD = 1e9 + 7;
const int MDL = 998244353;
const int INF = 1e9;
const int MX = 5e5 + 5;


int n;
pii a[MX];
ordered_set segm[4 * MX];
void buildtree(int cur, int start, int end) {
    if (start == end) {
    //BASE CASE
        segm[cur].insert(a[start]);
        return;
    }
    int mid = (start + end) >> 1;
    buildtree(cur << 1, start, mid);
    buildtree((cur << 1) + 1, mid + 1, end);

    for(auto &el:segm[2*cur])
        segm[cur].insert(el);
    for(auto &el:segm[2*cur+1])
        segm[cur].insert(el);
    //MERGING STEP


}
int query(int cur, int start, int end, int qs, int qe,int x) {
    if (start >= qs && end <= qe){
        int here=segm[cur].order_of_key(pii{x,0});
        return segm[cur].size()-here;
    }
    if (start > qe || end < qs)
        return 0;          //INVALID RETURN
    int mid = (start + end) >> 1;
    int A = query(2 * cur, start, mid, qs, qe,x);
    int B = query(2 * cur + 1, mid + 1, end, qs, qe,x);
//MERGING STEP
    int res = A+B;

    return res;
}
void update(int cur, int start, int end, int ind, int val) {
    if (start == ind && start == end) {
        //DO UPDATE
        segm[cur].erase(segm[cur].lower_bound(a[ind]));
        segm[cur].insert({val,ind});
        return;
    }
    if (start > ind || end < ind)
        return;          //OUT OF RANGE
    int mid = (start + end) >> 1;
    update(cur << 1, start, mid, ind, val);
    update((cur << 1) ^ 1, mid + 1, end, ind, val);
    segm[cur].erase(segm[cur].lower_bound(a[ind]));
    segm[cur].insert(pii{val,ind});
//MERGING STEP

}

int readInt () {
    bool minus = false;
    int result = 0;
    char ch;
    ch = getchar();
    while (true) {
        if (ch == '-') break;
        if (ch >= '0' && ch <= '9') break;
        ch = getchar();
    }
    if (ch == '-') minus = true; else result = ch-'0';
    while (true) {
        ch = getchar();
        if (ch < '0' || ch > '9') break;
        result = result*10 + (ch - '0');
    }
    if (minus)
        return -result;
    else
        return result;
}
void solve() {

    // cin >> n;
    // TimeLimitExceeded. use SQRT DECOMP
    n=readInt();
    repe(i, n)
        cin >> a[i].ff,a[i].ss=i;
    buildtree(1, 1, n);

    int q;
    // cin >> q;
    q=readInt();
    int t, aa, b, c;
    repe(i, q) {
        // cin >> t;
        t=readInt();
        aa=readInt();
        b=readInt();
        if (t == 0) {
            c=readInt();
            // cin >> aa >> b >> c;
            int ans = 0;//query(1, 1, n, aa, b, c);
            cout << ans << '\n';
        }
        else {
            // cin >> aa >> b;
            // update(1, 1, n, aa, b);
            a[aa].ff=b;
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
    repe(tt, t) {
        // cout<<"Case #"<<tt<<": ";
        solve();
    }

    // cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;

}
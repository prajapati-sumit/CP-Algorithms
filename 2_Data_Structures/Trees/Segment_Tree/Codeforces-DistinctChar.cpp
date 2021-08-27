//~ author      : Sumit Prajapati
#include <bits/stdc++.h>
using namespace std;


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




auto time0 = curtime;
const int MD = 1e9 + 7;
const int MDL = 998244353;
const int INF = 1e9;
const int MX = 1e5 + 5;

string s;
int segm[4 * MX];
void buildtree(int cur, int start, int end) {
    if (start == end) {
        //BASE CASE
        segm[cur]=(1<<(s[start]-'a'));
        return;
    }
    int mid = (start + end) >> 1;
    buildtree(cur << 1, start, mid);
    buildtree((cur << 1) + 1, mid + 1, end);
    //MERGING STEP
    segm[cur]=segm[2*cur] | segm[2*cur+1];


}
int query(int cur, int start, int end, int qs, int qe) {
    if (start >= qs && end <= qe)
        return segm[cur];
    if (start > qe || end < qs)
        return 0;          //INVALID RETURN
    int mid = (start + end) >> 1;
    int A = query(2 * cur, start, mid, qs, qe);
    int B = query(2 * cur + 1, mid + 1, end, qs, qe);
    //MERGING STEP
    int res = A|B;

    return res;
}
void update(int cur, int start, int end, int ind, char val) {
    if (start == ind && start == end) {
        //DO UPDATE
        segm[cur]=(1<<(val-'a'));
        return;
    }
    if (start > ind || end < ind)
        return;          //OUT OF RANGE
    int mid = (start + end) >> 1;
    update(cur << 1, start, mid, ind, val);
    update((cur << 1) ^ 1, mid + 1, end, ind, val);
    //MERGING STEP
    segm[cur]=segm[2*cur] | segm[2*cur+1];
}




void solve() {

    cin>>s;
    int q;
    cin>>q;
    int n=s.length();
    buildtree(1,0,n-1);
    repe(i,q){
        int t,x;
        cin>>t>>x;
        if(t==1){
            char y;
            cin>>y;
            update(1,0,n-1,x-1,y);
        }
        else{
            int y;
            cin>>y;
            int ans=query(1,0,n-1,x-1,y-1);
            ans=__builtin_popcount(ans);
            cout<<ans<<'\n';
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
//~ author      : Sumit Prajapati
#include <bits/stdc++.h>
using namespace std;


#define ull                 unsigned long long
#define ll                  long long
#define int                 long long
#define ld                  long double
#define pii                 pair<int, int>
#define pld                 pair<ld, ld>
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

int n, q;
ld a[MX];
ld segm[4 * MX];
pld lazy[4 * MX];
bool vis[4*MX];
void lazyUpdate(int cur,int start,int end){

    if(!vis[cur])
        return;
    ld ds=lazy[cur].ff,dn=lazy[cur].ss;
    lazy[cur]={1,0};
    vis[cur]=0;
    segm[cur]=ds*segm[cur]+dn*(end-start+1);
    if(start!=end){
        if(lazy[2*cur].ff==0)
            lazy[2*cur].ff=1;
        lazy[2*cur].ff*=ds;
        lazy[2*cur].ss=(lazy[2*cur].ss*ds)+dn;
        vis[2*cur]=1;

        if(lazy[2*cur+1].ff==0)
            lazy[2*cur+1].ff=1;
        lazy[2*cur+1].ff*=ds;
        lazy[2*cur+1].ss=(lazy[2*cur+1].ss*ds)+dn;
        vis[2*cur+1]=1;
    }


}
void buildtree(int cur, int start, int end) {
    if (start == end) {
        //BASE CASE
        segm[cur]=a[start];
        return;
    }
    int mid = (start + end) >> 1;
    buildtree(cur << 1, start, mid);
    buildtree((cur << 1) + 1, mid + 1, end);
    //MERGING STEP
    segm[cur]=segm[2*cur]+segm[2*cur+1];


}
bool flag;
ld query(int cur, int start, int end, int qs, int qe) {
    lazyUpdate(cur,start,end);
    if (start >= qs && end <= qe){
        return segm[cur];
    }
    if (start > qe || end < qs)
        return 0;          //INVALID RETURN
    int mid = (start + end) >> 1;
    ld A = query(2 * cur, start, mid, qs, qe);
    ld B = query(2 * cur + 1, mid + 1, end, qs, qe);
    //MERGING STEP
    ld res=A+B;
    return res;
}
void update(int cur, int start, int end, int qs, int qe,ld avo) {
    lazyUpdate(cur,start,end);
    if (start >= qs && end <= qe){
        int sz=qe-qs+1;
        lazy[cur]={(1-1.0/(sz)),avo/sz};
        vis[cur]=1;
        lazyUpdate(cur,start,end);
        return ;
    }
    if (start > qe || end < qs)
        return ;         //OUT OF RANGE
    int mid = (start + end) >> 1;
    update(cur << 1, start, mid, qs, qe,avo);
    update((cur << 1) ^ 1, mid + 1, end, qs,qe, avo);
    //MERGING STEP
    segm[cur]=segm[2*cur]+segm[2*cur+1];
}


void solve() {

    cin >> n >> q;
    repe(i, n)
        cin >> a[i];
    buildtree(1, 1, n);
    repe(i, q) {
        int ty;
        cin >> ty;
        if (ty == 1) {
            int l1, r1, l2, r2;
            cin >> l1 >> r1 >> l2 >> r2;
            ld s1=query(1,1,n,l1,r1);
            ld s2=query(1,1,n,l2,r2);



            s1/=(r1-l1+1);
            s2/=(r2-l2+1);
            update(1,1,n,l1,r1,s2);
            update(1,1,n,l2,r2,s1);
        }
        else {
            int l,r;
            cin>>l>>r;
            ld res=query(1,1,n,l,r);
            cout<<res<<'\n';
        }
    }



}


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    time0 = curtime;
    srand(time(NULL));
    int t = 1;
    cout<<setprecision(9)<<fixed;
    // cin>>t;
    repe(tt, t) {
        // cout<<"Case #"<<tt<<": ";
        solve();
    }

    // cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;

}
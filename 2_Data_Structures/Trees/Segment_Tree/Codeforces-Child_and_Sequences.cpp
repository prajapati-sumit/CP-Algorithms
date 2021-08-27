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
const int MX = 1e5 + 5;


int n;
int a[MX];
pii segm[4*MX];
void buildtree(int cur, int start, int end) {
    if (start == end) {
        //BASE CASE
        segm[cur]={a[start],start};
        return;
    }
    int mid = (start + end) >> 1;
    buildtree(cur << 1, start, mid);
    buildtree((cur << 1) + 1, mid + 1, end);
    //MERGING STEP
    segm[cur].ff=segm[2*cur].ff+segm[2*cur+1].ff;
    if(a[segm[2*cur].ss]>a[segm[2*cur+1].ss])
        segm[cur].ss=segm[2*cur].ss;
    else
        segm[cur].ss=segm[2*cur+1].ss;


}
pii query(int cur, int start, int end, int qs, int qe) {
    if (start >= qs && end <= qe)
        return segm[cur];
    if (start > qe || end < qs)
        return {0,0};          //INVALID RETURN
    int mid = (start + end) >> 1;
    pii A = query(2 * cur, start, mid, qs, qe);
    pii B = query(2 * cur + 1, mid + 1, end, qs, qe);
    //MERGING STEP
    pii res;
    res.ff=A.ff+B.ff;
    if(a[A.ss]>a[B.ss])
        res.ss=A.ss;
    else
        res.ss=B.ss;

    return res;
}
void update(int cur, int start, int end, int ind, int val) {
    if (start == ind && start == end) {
        //DO UPDATE
        segm[cur]={val,ind};
        return;
    }
    if (start > ind || end < ind)
        return;          //OUT OF RANGE
    int mid = (start + end) >> 1;
    update(cur << 1, start, mid, ind, val);
    update((cur << 1) ^ 1, mid + 1, end, ind, val);
    //MERGING STEP
    segm[cur].ff=segm[2*cur].ff+segm[2*cur+1].ff;
    if(a[segm[2*cur].ss]>a[segm[2*cur+1].ss])
        segm[cur].ss=segm[2*cur].ss;
    else
        segm[cur].ss=segm[2*cur+1].ss;
}



void solve() {

    int q;
    cin>>n>>q;
    a[0]=-1;
    repe(i,n)
        cin>>a[i];
    buildtree(1,1,n);
    int ans;
    repe(i,q){
        int t;
        cin>>t;
        if(t==1){
            int x,y;
            cin>>x>>y;
            ans=query(1,1,n,x,y).ff;
            cout<<ans<<'\n';
        }
        else if(t==2){
            int l,r,x;
            cin>>l>>r>>x;
            ans=query(1,1,n,l,r).ss;
            while(a[ans]>=x){
                a[ans]%=x;
                update(1,1,n,ans,a[ans]);
                ans=query(1,1,n,l,r).ss;
            }
        }
        else if(t==3){
            int x,y;
            cin>>x>>y;
            a[x]=y;
            update(1,1,n,x,y);

        }
        else assert(false);

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
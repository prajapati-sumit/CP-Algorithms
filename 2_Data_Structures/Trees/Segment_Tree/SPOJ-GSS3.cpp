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
const int MX = 50002;

struct Node{
    int pref,suff,sum,res;
};
int a[MX];
Node segm[4*MX];

void merge(Node& X,Node& Y,Node& Z){

    Z.pref=max(X.pref,X.sum+Y.pref);
    Z.suff=max(Y.suff,Y.sum+X.suff);
    Z.sum=X.sum+Y.sum;
    Z.res=max({X.res,Y.res,X.suff+Y.pref});

}
void buildtree(int cur, int start, int end) {
    if (start == end) {
        //BASE CASE
        segm[cur].pref=segm[cur].suff=segm[cur].sum=segm[cur].res=a[start];
        return;
    }
    int mid = (start + end) >> 1;
    buildtree(cur << 1, start, mid);
    buildtree((cur << 1) + 1, mid + 1, end);
    //MERGING STEP
    merge(segm[2*cur],segm[2*cur+1],segm[cur]);

}
Node query(int cur, int start, int end, int qs, int qe) {
    if (start >= qs && end <= qe)
        return segm[cur];
    if (start > qe || end < qs)
        return {-INF,-INF,-INF,-INF};          //INVALID RETURN
    int mid = (start + end) >> 1;
    Node A = query(2 * cur, start, mid, qs, qe);
    Node B = query(2 * cur + 1, mid + 1, end, qs, qe);
    //MERGING STEP
    Node res;
    merge(A,B,res);
    return res;
}
void update(int cur, int start, int end, int ind, int val) {
    if (start == ind && start == end) {
        //DO UPDATE
        segm[cur].pref=segm[cur].suff=segm[cur].sum=segm[cur].res=val;

        return;
    }
    if (start > ind || end < ind)
        return;          //OUT OF RANGE
    int mid = (start + end) >> 1;
    update(cur << 1, start, mid, ind, val);
    update((cur << 1) ^ 1, mid + 1, end, ind, val);
    //MERGING STEP
    merge(segm[2*cur],segm[2*cur+1],segm[cur]);
}



void solve() {
    int n;
    cin>>n;
    repe(i,n)
        cin>>a[i];
    buildtree(1,1,n);
    int q;
    cin>>q;
    repe(i,q){
        int t,x,y;
        cin>>t>>x>>y;
        if(t==0){
            update(1,1,n,x,y);
        }
        else{
            Node ans=query(1,1,n,x,y);
            cout<<ans.res<<'\n';
        }
    }


}


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    time0 = curtime;
    srand(time(NULL));
    int t = 1;
    // cin >> t;
    repe(tt, t) {
        // cout<<"Case #"<<tt<<": ";
        solve();
    }

    // cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;

}
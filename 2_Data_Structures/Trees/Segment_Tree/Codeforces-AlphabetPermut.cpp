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

struct Node {
    string pref;
    int count;
    string suff;
} segm[4 * MX];
char lazy[4 * MX];
string s;
int n, m, k;

bool isSubSequence(string& str1, string& str2){
    int m=str1.length(), int n=str2.length();
    int j = 0; 
    for (int i = 0; i < n && j < m; i++)
        if (str1[j] == str2[i])
            j++;
    return (j == m);
}
void merge(Node& A,Node& B,Node& res){

    res.pref=A.pref;
    res.suff=B.pref;

}
void buildtree(int cur, int start, int end) {
    if (start == end) {
        //BASE CASE
        segm[cur].pref=s.substr(start,1);
        segm[cur].count=1;
        segm[cur].suff=s.substr(start,1);
        return;
    }
    int mid = (start + end) >> 1;
    buildtree(cur << 1, start, mid);
    buildtree((cur << 1) + 1, mid + 1, end);
    //MERGING STEP
    merge(segm[2*cur],segm[2*cur+1],segm[cur]);


}
void lazyUpdate(){

}
int query(int cur, int start, int end, int qs, int qe) {
    if (start >= qs && end <= qe)
        return segm[cur];
    if (start > qe || end < qs)
        return ;          //INVALID RETURN
    int mid = (start + end) >> 1;
    int A = query(2 * cur, start, mid, qs, qe);
    int B = query(2 * cur + 1, mid + 1, end, qs, qe);
    //MERGING STEP
    int res =

        return res;
}
void update(int cur, int start, int end, int ind, int val) {
    if (start == ind && start == end) {
        //DO UPDATE

        return;
    }
    if (start > ind || end < ind)
        return;          //OUT OF RANGE
    int mid = (start + end) >> 1;
    update(cur << 1, start, mid, ind, val);
    update((cur << 1) ^ 1, mid + 1, end, ind, val);
    //MERGING STEP

}


void solve() {

    // Out of my league.
    cin >> n >> m >> k;
    s.clear();
    s.pb('$');
    repe(i,n)
        cin>>ch,s.pb(ch);
    repe(i, m) {
        int ty;
        cin >> ty;
        if (ty == 1) {

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
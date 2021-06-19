// AUTHOR: Sumit Prajapati      
#include <bits/stdc++.h>
using namespace std;


#define ull                 unsigned long long
// #define int                 long long           
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
#define curtime             chrono::high_resolution_clock::now()
#define timedif(start,end)  chrono::duration_cast<chrono::nanoseconds>(end - start).count()



auto time0 = curtime;
random_device rd;
default_random_engine generator(rd());
uniform_int_distribution<ull> distribution(0,0xFFFFFFFFFFFFFFFF);

const int MD=1e9+7;
const int MDL=998244353;
const int INF=1e9;
const int MX=1e5+5;

 

int n,k;


struct FenwickTree{
    vector<int> bit;  // binary indexed tree
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n + 1, 0);
    }

    FenwickTree(vector<int> a,int n):FenwickTree(a.size()) {
        for (int i = 1; i <= n; i++)
            add(i, a[i]);
    }

    int sum(int idx) {
        int ret = 0;
        for (; idx >=1; idx -= idx & -idx){
            ret += bit[idx];
        }
        return ret;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (; idx <= n; idx += idx & -idx)
            bit[idx] += delta;
    }
};
 
void solve(){
  
    cin>>n>>k;
    int x;
    FenwickTree fenw(n);
    fenw.add(3,5);
    fenw.add(2,6);
    cout<<fenw.sum(3,3)<<'\n';
    cout<<fenw.sum(2,2)<<'\n';
    cout<<fenw.sum(2,3)<<'\n';

    // repe(i,n){B
    //     cin>>x;
    //     if(firstOc[x]==0)
    //         firstOc[x]=i;
    //     lastOc[x]=i;
    // }      
    // buildtree(1,1,n);
    // int ty,l,r,ans=0;
    // repe(i,k){
    //     cin>>ty>>l>>r;
    //     if(ty==2){
    //         ans=query(1,1,n,l,r)
    //     }
    // }
 
} 
// 1 2 3 1 3 2 1
// 1->1,4,7
// 2->2,6
// 3->3,5

 
 
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    time0 = curtime;

    int t=1;
    cin>>t;
    repe(tt,t){
        // cout<<"Case #"<<tt<<": ";
        solve();
    }
    
    // cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;
 
}

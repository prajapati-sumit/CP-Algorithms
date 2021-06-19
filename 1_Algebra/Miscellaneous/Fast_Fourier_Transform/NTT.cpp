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

const int M=998244353, G=3;

// NTT -Credits :tmwilliam
ll pm(ll b, int p) {
    ll r=1;
    while(p) {
        if(p&1)
            r=r*b%M;
        b=b*b%M;
        p/=2;
    }
    return r;
}
struct ntt {
    ll rt[1<<20];
    void fi(int n) {
        rt[n/2]=1;
        rt[n/2+1]=pm(G, (M-1)/n);
        for(int i=n/2+2; i<n; ++i)
            rt[i]=rt[i-1]*rt[n/2+1]%M;
        for(int i=n/2; --i; )
            rt[i]=rt[2*i];
    }
    void ac(vector<ll> &a) {
        int n=a.size();
        for(int i=0, j=0; i<n; ++i) {
            if(i>j)
                swap(a[i], a[j]);
            for(int k=n/2; (j^=k)<k; k/=2);
        }
        for(int st=1; 2*st<=n; st*=2) {
            for(int i=0; i<n; i+=2*st) {
                for(int j=i; j<i+st; ++j) {
                    ll z=rt[j-i+st]*a[j+st]%M;
                    a[j+st]=a[j]-z;
                    if(a[j+st]<0)
                        a[j+st]+=M;
                    a[j]+=z;
                    if(a[j]>=M)
                        a[j]-=M;
                }
            }
        }
    }
};
ntt nt;


vector<ll> mult(vector<ll>& v, vector<ll>& w) {
    int s=v.size()+w.size()-1, t=1;
    while(t<s)
        t*=2;
    v.resize(t);
    w.resize(t);
    nt.ac(v);
    nt.ac(w);
    for(int i=0; i<t; ++i)
        v[i]=v[i]*w[i]%M*iv[t]%M;
    reverse(v.begin()+1, v.end());
    nt.ac(v);
    while(v.back()==0)
        v.pop_back();
    return v;
}



void solve() {

    vector<int>a={2,-3,1},b={-3,1};
    vector<int>res;
    // for(auto &el:a)
    //     cout<<el<<" ";
    // cout<<'\n';
    res=mult(a,b);
    for(auto &el:res){
        if(el>20)
            cout<<(el-M)<<" ";
        else
            cout<<el<<" ";

    }
    cout<<'\n';


}


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    nt.fi(1<<20);
    iv[1]=1;
    for(int i=2; i<=1<<20; ++i)
        iv[i]=M-M/i*iv[M%i]%M;

    time0 = curtime;
    srand(time(NULL));
    int t = 1;
    cin >> t;
    repe(tt, t) {
        // cout<<"Case #"<<tt<<": ";
        solve();
    }

    // cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;

}
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
#define SZ(x)               ((int)x.size())
#define set_bits            __builtin_popcountll
#define all(a)              a.begin(),a.end()
#define trav(x,v)           for(auto &x:v)
#define rep(i,n)            for(int i=0;i<n;i++)
#define repe(i,n)           for(int i=1;i<=n;i++)
#define FOR(i,a,b)          for(int i=a;i<=b;i++)
#define curtime             chrono::high_resolution_clock::now()
#define timedif(start,end)  chrono::duration_cast<chrono::nanoseconds>(end - start).count()




const int MD = 1e9 + 7;
const int MDL = 998244353;
const int INF = 1e9;
const int MX = 1e6 + 5;




int p[MX];
string s;

void solve() {

    cin>>s;
    int n=s.length();
    rep(i,n)
        p[i]=0;    
    p[n-1]=(s[0]==s[n-1]);
    int ind=0,len=1;
    for(int j=n-2;j>=0;j--){
        if(s[p[j+1]]==s[j])
            p[j]=1+p[j+1];
        else
            p[j]=(s[0]==s[j]);

        if(len<p[j]){
            ind=j;
            len=p[j];
        }
    }
    // cout<<ind<<" "<<len<<'\n';
    cout<<s.substr(ind,len)<<'\n';


}


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    auto time0 = curtime;
    int t = 1;
    cin >> t;
    repe(tt, t) {
        // cout<<"Case #"<<tt<<": ";
        solve();
    }

    // cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;

}
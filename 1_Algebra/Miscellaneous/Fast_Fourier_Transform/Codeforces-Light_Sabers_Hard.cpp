//CODED BY SUMIT KUMAR PRAJAPATI
#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int>  pii;
typedef pair<ll, ll>  pl;

#define PI 3.1415926535897932384626
#define pb push_back
#define mk make_pair
#define ff first
#define ss second
#define trav(v) for(auto &el:v)
#define watch(x) cerr<<#x<<" = "<<x<<'\n'
#define rep(i,n) for(ll i=0;i<n;i++)
#define repe(i,n) for(ll i=1;i<=n;i++)
#define FOR(i,a,b) for(ll i=a;i<=b;i++)
#define printar(a,s,e) FOR(i,s,e)cout<<a[i]<<" ";cout<<'\n'
#define curtime chrono::high_resolution_clock::now()
#define timedif(start,end) chrono::duration_cast<chrono::nanoseconds>(end - start).count()

const int INF=1e9;
const ll MX=1<<18;
const ll MD=1009;
const int MDL=998244353;
auto time0 = curtime;
 


typedef complex<long double> Complex;

void display(Complex C){
    char ch;
    if(C.imag()<0)
        ch='-';
    else
        ch='+';
    cout<<C.real()<<ch<<C.imag()<<"i "; 
}
ll rev(ll x,ll sz){
    ll res=0;
    rep(i,sz){
        res<<=1;
        res=res|(x&1!=0);
        x>>=1;
    }
   

    return res;
}

void FFT(vector<Complex>& a,bool invert){
    ll sz=0;
    ll n=a.size();
    while((1<<sz)<n)
        sz++;
    a.resize((1<<sz));
    n=(1<<sz);
    rep(i,n){
        ll r=rev(i,sz);
        if(i<r)
            swap(a[i],a[r]);
    }
    Complex wlen;
    long double arg,one=1.0;
    for(int len=2;len<=n;len<<=1){
        arg=2*PI/len* ( invert ? -1 : 1);
        wlen=polar(one,arg);
        for (ll i = 0; i < n; i += len) {
            Complex w(1);
            for (ll j = 0; j < len / 2; j++) {
                Complex u = a[i+j], v = a[i+j+len/2] * w;
                a[i+j] = u + v;
                a[i+j+len/2] = u - v;
                w *= wlen;
            }
        }
    }

    if(invert){
        for(auto &x:a)
            x/=n;
    }
} 
void multiply(vector<ll>& a, vector<ll>& b) {
    vector<Complex> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    ll n = 1;
    while (n < a.size() + b.size()) 
        n <<= 1;
    fa.resize(n);
    fb.resize(n);

    FFT(fa, false);
    FFT(fb, false);
    for (ll i = 0; i < n; i++)
        fa[i] *= fb[i];
    FFT(fa, true);

    a.resize(n);
    for (ll i = 0; i < n; i++){
        a[i] = round(fa[i].real());
        a[i]%=MD;
    }
    

} 

void  binary_multiply(vector<ll>x, ll p,vector<ll>& res){

    
    while(p){
        if(p&1)
            multiply(res,x);
        
        multiply(x,x);
        p>>=1;
        
    }
    
}  
 
 
 
void solve(){
  
    ll n,m,k;
    cin>>n>>m>>k;
    if(m==1){
        cout<<"1";
        return;
    }

    ll colors[m+1],x;
    repe(i,m)
        colors[i]=1;
    repe(i,n)
        cin>>x,colors[x]++;

    sort(colors+1,colors+m+1);
    map<int,int>mp;
    repe(i,m){
        if(colors[i]!=1)
            mp[colors[i]]++;
    }
    vector<ll>res{1},temp; 
    // printar(colors,1,m);
    // for(auto el:mp)
    //     cout<<el.ff<<" "<<el.ss<<"\n";
    vector<ll>a;
    for(auto &el:mp){
        ll p=el.ss,sz=el.ff;
        while(a.size()<sz){
            a.pb(1);
        }
        temp.clear();
        temp.pb(1);
        binary_multiply(a,p,temp);
        // trav(temp)
        //     cout<<el<<" ";
        // cout<<'\n';
        multiply(res,temp);
        
    }
    // cout<<res[k]<<'\n';
    ll ans=res[k]%MD;
    cout<<ans<<'\n';
} 
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    srand(time(0)); 
    time0 = curtime;

    ll t=1;
    //cin>>t;
    repe(tt,t){
        //cout<<"Case #"<<tt<<": ";
        solve();
    }
    
    cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;
 
}
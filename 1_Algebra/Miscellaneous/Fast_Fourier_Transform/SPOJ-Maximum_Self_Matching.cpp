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
#define watch(x) cerr<<#x<<" = "<<x<<'\n'
#define rep(i,n) for(ll i=0;i<n;i++)
#define repe(i,n) for(ll i=1;i<=n;i++)
#define FOR(i,a,b) for(ll i=a;i<=b;i++)
#define printar(a,s,e) FOR(i,s,e)cout<<a[i]<<" ";cout<<'\n'
#define curtime chrono::high_resolution_clock::now()
#define timedif(start,end) chrono::duration_cast<chrono::nanoseconds>(end - start).count()

const int INF=1e9;
const int MX=1e6+5;
const int MD=1e9+7;
const int MDL=99824453;
auto time0 = curtime;
 
typedef complex<double> Complex;

void display(Complex C){
    char ch;
    if(C.imag()<0)
        ch='-';
    else
        ch='+';
    cout<<C.real()<<ch<<abs(C.imag())<<"i "<<": "<<abs(C); 
}
int rev(int x,int sz){
    int res=0;
    rep(i,sz){
        res<<=1;
        res=res|(x&1!=0);
        x>>=1;
    }
   

    return res;
}

void FFT(vector<Complex>& a,bool invert){
    int sz=0;
    int n=a.size();
    while((1<<sz)<n)
        sz++;
    a.resize((1<<sz));
    n=(1<<sz);
    rep(i,n){
        int r=rev(i,sz);
        if(i<r)
            swap(a[i],a[r]);
    }
    Complex wlen;
    double arg;
    for(int len=2;len<=n;len<<=1){
        arg=2*PI/len* ( invert ? -1 : 1);
        wlen=polar(1.0,arg);
        for (int i = 0; i < n; i += len) {
            Complex w(1);
            for (int j = 0; j < len / 2; j++) {
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
vector<int> multiply(vector<int> const& a, vector<int> const& b) {
    vector<Complex> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < a.size() + b.size()) 
        n <<= 1;
    fa.resize(n);
    fb.resize(n);
    FFT(fa, false);
    FFT(fb, false);
    for (int i = 0; i < n; i++)
        fa[i] *= fb[i];
    FFT(fa, true);
    vector<int> result(n);
    for (int i = 0; i < n; i++)
        result[i] = round(fa[i].real());
    return result;
} 
 
 
 
 

void solve(){
   
    //Nice..!!
    string s;
    cin>>s;
    int N=s.length();
    string v=s,u=s;
    rep(i,N)
        v.pb('d');
    int n=v.length(),k=u.length(),m=4;
    vector<int>p(MX,0),q(MX,0);
    repe(i,n)
        p[i*(m+1)+v[i-1]-'a'+1]+=1;
    repe(j,k)
        q[(k-j)*(m+1)+(m-(u[j-1]-'a'+1))]+=1;
    vector<int> r=multiply(p,q);
    int sz=r.size();
    int mx=-1;
    for(int i=m*k+k+2*m+1,ind=2;i<sz && ind<=k;i+=(m+1),ind++){
        mx=max(r[i],mx);   
    }
    cout<<mx<<'\n';
    for(int i=m*k+k+2*m+1,ind=2;i<sz&&ind<=k;i+=(m+1),ind++){
        if(r[i]==mx)
            cout<<ind-1<<" ";  
    }
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
    
    
    return 0;
 
}                               
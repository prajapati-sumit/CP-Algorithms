//CODED BY SUMIT KUMAR PRAJAPATI
#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int>  pii;
typedef pair<ll, ll>  pl;
typedef pair<char,char> pcc;

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
const int MX=1e5+5;
const int MD=1e9+7;
const int MDL=998244353;
auto time0 = curtime;
 
 
 
vector<int>v[6]; 
bool freq[6];
void dfs(int node){
    freq[node]=false;
    trav(v[node]){
        if(freq[el])
            dfs(el);
    }
    
}
typedef complex<double> Complex;

void display(Complex C){
    char ch;
    if(C.imag()<0)
        ch='-';
    else
        ch='+';
    cout<<C.real()<<ch<<C.imag()<<"i "; 
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
  
    string T="abcdefa",P="ddcb";
    //cin>>T>>P;
    int n=T.length(),m=P.length();
    map<pcc,vector<int>>mp;
    for(char i='a';i<='f';i++)
        for(char j=i;j<='f';j++)
            mp[{i,j}].pb(0);
    // trav(mp)
    //     cout<<el.ff.ff<<" "<<el.ff.ss<<" \n";   
    vector<int>A,B;
    trav(mp){
        char ch1=el.ff.ff,ch2=el.ff.ss;

        A.clear();
        B.clear();

        rep(i,n)
            if(T[i]==ch1 || T[i]==ch2)
                A.pb(1);
            else
                A.pb(0);
        rep(i,m)
            if(P[i]==ch1 || P[i]==ch2)
                B.pb(1);
            else
                B.pb(0);

        reverse(B.begin(),B.end());
        el.ss=multiply(A,B);
        
    }   
    vector<int>res;
    //cout<<mp.size()<<'\n';
    FOR(i,m-1,n-1){
        int cnt=0;
        
        rep(i,6){
            freq[i]=0;
            v[i].clear();
        }
        trav(mp){
            char ch1=el.ff.ff,ch2=el.ff.ss;
            // if(i==m-1){
            //     cout<<el.ff.ff<<" "<<el.ff.ss<<": "<<el.ss[i]<<'\n';
            // }
            if(ch1!=ch2 && el.ss[i] > (mp[{ch1,ch1}][i]+mp[{ch2,ch2}][i])){
                v[ch1-'a'].pb(ch2-'a');
                v[ch2-'a'].pb(ch1-'a');
                freq[ch1-'a']=true;
                freq[ch2-'a']=true;
            }
            else if(ch1==ch2 && el.ss[i]>0)
                freq[ch1-'a']=true;

        }
        rep(i,6)
            cnt+=freq[i];
        int cc=0;
        rep(i,6)
            if(freq[i]){
                dfs(i);
                cc++;
            }

        res.pb(cnt-cc);
    }
    trav(res)
        cout<<el<<" ";


//cfafeeebcecbabc
//fafbffdefbeeddcdcfcefebeaccc


 
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
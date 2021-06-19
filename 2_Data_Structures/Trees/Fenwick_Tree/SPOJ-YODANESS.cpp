// AUTHOR: Sumit Prajapati      
#include <bits/stdc++.h>
using namespace std;


#define ull                 unsigned long long
#define ll                  long long           
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
#define endl                '\n'
#define curtime             chrono::high_resolution_clock::now()
#define timedif(start,end)  chrono::duration_cast<chrono::nanoseconds>(end - start).count()
#define INF                 1'000'000'000
#define MD                  1'000'000'007
#define MDL                 998244353
#define MX                  30005


auto time0 = curtime;
random_device rd;
default_random_engine generator(rd());
uniform_int_distribution<ull> distribution(0,0xFFFFFFFFFFFFFFFF);

//Is testcase present?
 
 
string s[MX]; 

void printvec(vector<int>& v){
    for(auto& el:v)
        cout<<el<<" ";
    cout<<'\n';
}
ll fn(vector<int>& a,ll l,ll r){
    if(l>=r)
        return 0;

    ll mid=(l+r)>>1;

    vector<int>Le,Ri;
    rep(i,mid-l+1)
        Le.pb(a[i]);
    FOR(i,mid-l+1,r-l)
        Ri.pb(a[i]);
    
    ll lef=fn(Le,l,mid),rig=fn(Ri,mid+1,r);
    int i=0,j=0;
    
    ll cnt=0;
    ll count=0;
    int szi=Le.size(),szj=Ri.size();
    while(i<szi && j<szj ){
        if(Le[i]<Ri[j]){
            a[cnt++]=Le[i];
            i++;
        }
        else{
            count+=(szi-i);
            a[cnt++]=Ri[j];
            j++;
        }
    }
    while(i<szi)
       a[cnt++]=(Le[i]),i++; 
    while(j<szj)
       a[cnt++]=(Ri[j]),j++; 
    // cout<<l<<" "<<r<<"--\n";
    // printvec(a);
    // printvec(Le);
    // printvec(Ri);
    // cout<<"-------\n";
    return lef+rig+count;


}
void solve(){
    
    int n;
    cin>>n;
    rep(i,n)
        cin>>s[i];
    string temp;
    map<string,int>mp;
    rep(i,n){
        cin>>temp;
        mp[temp]=i;
    }
    vector<int> a(n);
    rep(i,n)
        a[i]=mp[s[i]];
    // printvec(a);
    ll ans=fn(a,0,n-1);
    // printvec(a);
    cout<<ans<<'\n';
  
 
} 
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    time0 = curtime;

    int t=1;
    cin>>t;
    repe(tt,t){
        //cout<<"Case #"<<tt<<": ";
        solve();
    }
    
    //cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;
 
}
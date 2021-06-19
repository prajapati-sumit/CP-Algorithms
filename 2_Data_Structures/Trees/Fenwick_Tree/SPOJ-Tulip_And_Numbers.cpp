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
#define MX                  100'00005


auto time0 = curtime;
random_device rd;
default_random_engine generator(rd());
uniform_int_distribution<ull> distribution(0,0xFFFFFFFFFFFFFFFF);

//Is testcase present?
 
 
void fastscan(int &x)
{
    bool neg=false;
    int c;
    x =0;
    c=getchar();
    if(c=='-')
    {
        neg = true;
        c=getchar();
    }
    for(;(c>47 && c<58);c=getchar())
        x = (x<<1) + (x<<3) +c -48;
    if(neg)
        x *=-1;
} 
stringstream sst;
void solve(){
  
    int n,q;
    // cin>>n>>q;
    fastscan(n);
    fastscan(q);
    int a[n+1];
    // unordered_map<int,int>mp;
    int cnt=1;
    int prev=-1;
    repe(i,n){
        fastscan(a[i]);
        // cout<<prev<<" "<<a[i]<<'\n';
        if(a[i]!=prev){
            prev=a[i];
            a[i]=cnt++;
        }  
        else
            a[i]=cnt-1;
    }
    // repe(i,n)
    //     a[i]=mp[a[i]];
    // repe(i,n)
    //     sst<<a[i]<<" \n"[i==n];

    repe(i,q){
        int l,r;
        // cin>>l>>r;
        fastscan(l);
        fastscan(r);
        sst<<(a[r]-a[l]+1)<<'\n';
        // printf("%d\n",(a[r]-a[l]+1));
    }
  
 
} 
 
 
int main() {

    time0 = curtime;

    int t=1;
    fastscan(t);
    
    repe(tt,t){
        sst<<"Case "<<tt<<":\n";
        // printf("Case %d:\n",tt);
        solve();
    }
    cout<<sst.str();
    //cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;
 
}
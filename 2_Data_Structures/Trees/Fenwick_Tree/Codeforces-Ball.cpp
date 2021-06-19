// AUTHOR: Sumit Prajapati      
#include <bits/stdc++.h>
using namespace std;


#define ull                 unsigned long long
#define int                 long long           
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
const int MX=15e5+5;

 
int n;
int segm[4*MX]; 

int query(int cur,int start,int end,int qs,int qe){
    if(start>=qs && end<=qe)
        return segm[cur];
    if(start>qe || end<qs)
        return 0;          //INVALID RETURN 
    int mid=(start+end)>>1;
    int A=query(2*cur,start,mid,qs,qe);
    int B=query(2*cur+1,mid+1,end,qs,qe);
    //MERGING STEP
    int res=max(A,B);  

    return res;
}
void update(int cur,int start,int end,int ind,int val){
    if(start==ind && start==end){
        //DO UPDATE
        segm[cur]=max(segm[cur],val);
        return;
    }
    if(start>ind|| end<ind)
        return;          //OUT OF RANGE 
    int mid=(start+end)>>1;
    update(cur<<1,start,mid,ind,val);
    update((cur<<1)^1,mid+1,end,ind,val);
    //MERGING STEP
    segm[cur]=max(segm[2*cur],segm[2*cur+1]);
    
}
vector<int>to_compress;
void solve(){
  
    cin>>n;
    int x,y,z;
    map<int,int>mp;
    vector<pair<int,pii>>v(n);
    int cnt=1;
    rep(i,n){
        cin>>x;
        v[i].ff=x;
        to_compress.pb(x);
    }
    rep(i,n){
        cin>>y;
        to_compress.pb(y);
        v[i].ss.ff=y;
    }
    rep(i,n){
        cin>>z;
        v[i].ss.ss=z;
        to_compress.pb(z);
    }

    
    sort(all(to_compress));
    for(auto &el:to_compress)
        if(mp[el]==0)
            mp[el]=cnt++;
    rep(i,n){
        v[i].ff=mp[v[i].ff];
        v[i].ss.ff=mp[v[i].ss.ff];
        v[i].ss.ss=mp[v[i].ss.ss];
    }
    sort(all(v));
    assert(cnt<MX);
    int ans=0;
    int cur=INF;
    vector<pii>temp;
    for(int i=n-1;i>=0;i--){

        x=v[i].ff;
        y=v[i].ss.ff;
        z=v[i].ss.ss;
        if(cur!=x){
            for(auto&el:temp)
                update(1,1,cnt,el.ff,el.ss);
            temp.clear();
            cur=x;
        }
        temp.pb({y,z});
        // cout<<x<<" "<<y<<" "<<z<<' ';
        // int l=i+1,r=
        int max_here=query(1,1,cnt,y+1,cnt);
        if(max_here>z){
            // cout<<i<<" **";
            ans++;
        }
        // cout<<'\n';
        
    }
    cout<<ans<<'\n';
} 
 
 
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    time0 = curtime;

    int t=1;
    // cin>>t;
    repe(tt,t){
        // cout<<"Case #"<<tt<<": ";
        solve();
    }
    
    // cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;
 
}
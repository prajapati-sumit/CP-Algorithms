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
const int MD=1e9+7;
const int MDL=998244353;
const int INF=1e16;
const int MX=2e5+5;

 
int n,m;
int a[MX];
int segm[4*MX],lazy[4*MX];
 
string s;
void buildtree(int cur,int start,int end){
    if(start==end){
       //BASE CASE
        segm[cur]=a[start];
        return;
    }
    int mid=(start+end)>>1;
    buildtree(cur<<1,start,mid);
    buildtree((cur<<1)+1,mid+1,end);
    //MERGING STEP
    segm[cur]=min(segm[cur<<1],segm[(cur<<1)^1]);



}
int query(int cur,int start,int end,int qs,int qe){
    if(lazy[cur]!=0){
        int dx=lazy[cur];
        lazy[cur]=0;
        segm[cur]+=dx;
        if(start!=end){
            lazy[2*cur]+=dx;
            lazy[2*cur+1]+=dx;
        }
    }
    if(start>=qs && end<=qe)
        return segm[cur];
    if(start>qe || end<qs)
        return INF;          //INVALID RETURN 
    int mid=(start+end)>>1;
    int A=query(2*cur,start,mid,qs,qe);
    int B=query(2*cur+1,mid+1,end,qs,qe);
    //MERGING STEP
    int res=min(A,B);  

    return res;
}
void update(int cur,int start,int end,int qs,int qe,int inc){
    if(lazy[cur]!=0){
        int dx=lazy[cur];
        lazy[cur]=0;
        segm[cur]+=dx;
        if(start!=end){
            lazy[2*cur]+=dx;
            lazy[2*cur+1]+=dx;
        }
    }
    if(start>=qs && end<=qe){
        segm[cur]+=inc;
        if(start!=end){
            lazy[2*cur]+=inc;
            lazy[2*cur+1]+=inc;
        }
        return;

    }
    if(start>qe || end<qs)
        return ;            //OUT OF RANGE 
    int mid=(start+end)>>1;
    update(cur<<1,start,mid,qs,qe,inc);
    update((cur<<1)^1,mid+1,end,qs,qe,inc);
    //MERGING STEP
    segm[cur]=min(segm[2*cur],segm[2*cur+1]);
}

void solve(){
  
    scanf("%lld\n",&n);
    repe(i,n){
        scanf("%lld\n",&a[i]);
    }
    buildtree(1,1,n);
    scanf("%lld\n",&m);
    repe(i,m){
        
        getline(cin,s);
        stringstream sst(s);
        vector<int>v;
        int x,y;
        while(sst>>x)
            v.pb(x);
        if(v.size()==2){
            x=v[0];
            y=v[1];
            x++;
            y++;
            int ans;
            if(x<=y)
                ans=query(1,1,n,x,y);
            else{
                ans=min(query(1,1,n,x,n),
                query(1,1,n,1,y));
            }
            cout<<ans<<'\n';
        }
        else if(v.size()==3){
            x=v[0];
            y=v[1];
            x++;
            y++;
            int inc=v[2];
            if(x<=y){
                update(1,1,n,x,y,inc);
            }
            else{
                update(1,1,n,x,n,inc);
                update(1,1,n,1,y,inc);
            }
        }
        else
            assert(false);
    }
 
} 
 
 
int32_t main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    time0 = curtime;
    srand(time(NULL));
    int t=1;
    // cin>>t;
    repe(tt,t){
        // cout<<"Case #"<<tt<<": ";
        solve();
    }
    
    // cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;
 
}
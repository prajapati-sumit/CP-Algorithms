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
const int INF=1e9;
const int MX=2e5+5;

 
 
int segm[4*MX];
pii lazy[4*MX];
int a[MX];

void merge(int &A,int &B,int &res){
    res=A+B;
}
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
    merge(segm[2*cur],segm[2*cur+1],segm[cur]);
}

void lazyUpdate(int cur,int start,int end){

    if(!lazy[cur].ff)
        return;
    int dx=lazy[cur].ff,ty=lazy[cur].ss;
    lazy[cur]={0,0};
    if(ty==0){
        segm[cur]=dx*(end-start+1);
    }
    else{
        segm[cur]+=dx*(end-start+1);
    }
    if(start!=end){

        if(ty==0){
            lazy[2*cur]={dx,ty};
            lazy[2*cur+1]={dx,ty};
        }
        else{
            if(lazy[2*cur].ff==0)
                lazy[2*cur].ss=ty;
            lazy[2*cur].ff+=dx;
            if(lazy[2*cur+1].ff==0)
                lazy[2*cur+1].ss=ty;
            lazy[2*cur+1].ff+=dx;
        }
    }
}
int query(int cur,int start,int end,int qs,int qe){

    lazyUpdate(cur,start,end);
    if(start>=qs && end<=qe)
        return segm[cur];
    if(start>qe || end<qs)
        return 0;          //INVALID RETURN 
    int mid=(start+end)>>1;
    int A=query(2*cur,start,mid,qs,qe);
    int B=query(2*cur+1,mid+1,end,qs,qe);
    //MERGING STEP
    int res;
    merge(A,B,res);  

    return res;
}
void update(int cur,int start,int end,int qs,int qe,int x,bool ty){

    lazyUpdate(cur,start,end);

    if(start>=qs && end<=qe){
        //DO UPDATE
        lazy[cur]={x,ty};
        lazyUpdate(cur,start,end);
        return;
    }
    if(start>qe|| end<qs)
        return;          //OUT OF RANGE 
    int mid=(start+end)>>1;
    update(cur<<1,start,mid,qs,qe,x,ty);
    update((cur<<1)^1,mid+1,end,qs,qe,x,ty);
    //MERGING STEP
    merge(segm[2*cur],segm[2*cur+1],segm[cur]);

}
 
 
 
void solve(){
  
    int n,q;
    cin>>n>>q;
    repe(i,n)
        cin>>a[i];
    buildtree(1,1,n);  
    repe(i,q){
        int ty;
        cin>>ty;
        if(ty==1){
            int l,r,x;
            cin>>l>>r>>x;
            // +=x
            update(1,1,n,l,r,x,1);
            // repe(i,n)
            //     cout<<query(1,1,n,i,i)<<" \n"[i==n];
        }
        else if(ty==2){
            int l,r,x;
            cin>>l>>r>>x;
            // =x
            update(1,1,n,l,r,x,0);
            // repe(i,n)
            //     cout<<query(1,1,n,i,i)<<" \n"[i==n];
        }
        else if(ty==3){
            int l,r;
            cin>>l>>r;
            // sum
            cout<<query(1,1,n,l,r)<<'\n';
        }
        else
            assert(0);
    }   
  
 
} 
 
 
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

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
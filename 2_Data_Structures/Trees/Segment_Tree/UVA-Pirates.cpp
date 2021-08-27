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
const int MX=1e5+5;

const int nax= 1024001; 
 
int bits[nax];
pii segm[4*nax];
int lazy[4*nax];
int n; 
void buildtree(int cur,int start,int end){
    if(start==end){
       //BASE CASE
        segm[cur]={bits[start]==1,bits[start]==0};
        return;
    }
    int mid=(start+end)>>1;
    buildtree(cur<<1,start,mid);
    buildtree((cur<<1)+1,mid+1,end);
    //MERGING STEP
    segm[cur].ff=segm[2*cur].ff+segm[2*cur+1].ff;
    segm[cur].ss=segm[2*cur].ss+segm[2*cur+1].ss;


}
void lazyUpdate(int cur,int start,int end){
    if(lazy[cur]==-1)
        return;
    if(start!=end){
        int mid=(start+end)>>1;
        lazyUpdate(2*cur,start,mid);
        lazyUpdate(2*cur+1,mid+1,end);
        lazy[2*cur]=lazy[cur];
        lazy[2*cur+1]=lazy[cur];
    }
    if(lazy[cur]==1){
        // All 1's
        segm[cur].ff=segm[cur].ff+segm[cur].ss;
        segm[cur].ss=0;
    }
    if(lazy[cur]==2){
        // All 0's
        segm[cur].ss=segm[cur].ff+segm[cur].ss;
        segm[cur].ff=0;   
    }
    if(lazy[cur]==3){
        // Flip bits
        swap(segm[cur].ff,segm[cur].ss);
    }
    lazy[cur]=-1;
}
int query(int cur,int start,int end,int qs,int qe){
    lazyUpdate(cur,start,end);
    if(start>=qs && end<=qe){
        // cout<<cur<<": ";
        // cout<<start<<" "<<end<<" "<<segm[cur].ff<<" "<<segm[cur].ss<<'\n';
        return segm[cur].ff;
    }
    if(start>qe || end<qs)
        return 0;          //INVALID RETURN 
    int mid=(start+end)>>1;
    int A=query(2*cur,start,mid,qs,qe);
    int B=query(2*cur+1,mid+1,end,qs,qe);
    //MERGING STEP
    int res=A+B;  

    return res;
}

void update(int cur,int start,int end,int qs,int qe,int ty){
    lazyUpdate(cur,start,end);
    if(start>=qs && end<=qe){
        //DO UPDATE
        lazy[cur]=ty;
        lazyUpdate(cur,start,end);
        return;
    }
    if(start>qe|| end<qs)
        return;          //OUT OF RANGE 
    int mid=(start+end)>>1;
    update(cur<<1,start,mid,qs,qe,ty);
    update((cur<<1)^1,mid+1,end,qs,qe,ty);
    //MERGING STEP
    segm[cur].ff=segm[2*cur].ff+segm[2*cur+1].ff;
    segm[cur].ss=segm[2*cur].ss+segm[2*cur+1].ss;
}

void solve(){
  
    int m;
    cin>>m;
    int freq;
    string s;
    n=1;
    repe(i,m){
        cin>>freq;
        cin>>s;
        repe(i,freq){
            for(auto &el:s)
                bits[n++]=(el=='1');
        }
    }
    n--;
    repe(i,4*n)
        lazy[i]=-1;
    buildtree(1,1,n);
    // repe(i,n)
    //     cout<<bits[i];
    // cout<<'\n';
    // update(1,1,n,1,n,1);
    // update(1,1,n,1,4,3);
    // update(1,1,n,4,6,3);
    // cout<<query(1,1,n,4,8)<<'\n';
    // return;
    int q;
    cin>>q;
    char ch;
    int x,y;
    int qu=1,ans=0;
    repe(i,q){
        cin>>ch>>x>>y;
        x++;
        y++;
        if(ch=='F'){
            update(1,1,n,x,y,1);
        }
        else if (ch=='I'){
            update(1,1,n,x,y,3);
        }
        else if (ch=='S'){
            ans=query(1,1,n,x,y);
            
            cout<<"Q"<<qu++<<": "<<ans<<'\n';
        }
        else if(ch=='E'){
            update(1,1,n,x,y,2);
        }
        else
            assert(false);

    }
    
 
} 
 
 
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    time0 = curtime;
    srand(time(NULL));
    int t=1;
    cin>>t;
    repe(tt,t){
        cout<<"Case "<<tt<<": \n";
        solve();
    }
    
    // cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;
 
}
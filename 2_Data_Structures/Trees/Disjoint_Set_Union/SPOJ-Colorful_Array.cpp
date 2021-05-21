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
#define MX                  200'005


auto time0 = curtime;
random_device rd;
default_random_engine generator(rd());
uniform_int_distribution<ull> distribution(0,0xFFFFFFFFFFFFFFFF);

//Is testcase present?
 
int n,q;
int segm[4*MX],lazy[4*MX],a[MX]; 

int query(int cur,int start,int end,int qs,int qe){
    if(lazy[cur]!=0){
        segm[cur]=lazy[cur];
        if(start!=end){
            lazy[2*cur]=lazy[cur];
            lazy[2*cur+1]=lazy[cur];
        }
        lazy[cur]=0;
    }
    if(start>=qs && end<=qe)
        return segm[cur];
    if(start>qe || end<qs)
        return 0;          //INVALID RETURN 
    int mid=(start+end)>>1;
    int A=query(2*cur,start,mid,qs,qe);
    int B=query(2*cur+1,mid+1,end,qs,qe);
    int res=A+B ;             //MERGING STEP  

    return res;
}
void update(int cur,int start,int end,int l,int r,int val){
    if(lazy[cur]!=0){
        segm[cur]=lazy[cur];
        if(start!=end){
            lazy[2*cur]=lazy[cur];
            lazy[2*cur+1]=lazy[cur];
        }
        lazy[cur]=0;
    }
    if(start>=l && end<=r){
    //DO UPDATE

        segm[cur]=val;
        if(start!=end){
            lazy[2*cur]=val;
            lazy[2*cur+1]=val;
        }
        return; 

    }
    if(start>r|| end<l)
        return;          //OUT OF RANGE 
    int mid=(start+end)>>1;
    update(cur<<1,start,mid,l,r,val);
    update((cur<<1)^1,mid+1,end,l,r,val);
    //MERGING STEP
}
//LAZY PROPAGATION
 
void solve(){
  
    cin>>n>>q;
    int l,r,x;
    while(q--){
        cin>>l>>r>>x;
        update(1,1,n,l,r,x);
        // repe(i,2*n)
        //     cerr<<segm[i]<<" \n"[i==2*n];
        // repe(i,2*n)
        //     cerr<<lazy[i]<<" \n"[i==2*n];
        // cerr<<'\n';
    }       
    repe(i,n)
        cout<<query(1,1,n,i,i)<<'\n';

 
} 
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    time0 = curtime;

  
    solve();
    

    //cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;
 
}
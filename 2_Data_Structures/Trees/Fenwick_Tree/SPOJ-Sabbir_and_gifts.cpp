// AUTHOR: Sumit Prajapati      
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
#define MX                  100'005


auto time0 = curtime;
random_device rd;
default_random_engine generator(rd());
uniform_int_distribution<ull> distribution(0,0xFFFFFFFFFFFFFFFF);

//Is testcase present?
 
 
int n;
int a[MX];
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
     int res=A+B; 
 
     return res;
}
 void update(int cur,int start,int end,int ind,int val){
     if(start==ind && start==end){
         //DO UPDATE
        segm[cur]=val;
         return;
     }
     if(start>ind|| end<ind)
         return;          //OUT OF RANGE 
     int mid=(start+end)>>1;
     update(cur<<1,start,mid,ind,val);
     update((cur<<1)^1,mid+1,end,ind,val);
    segm[cur]=segm[2*cur]+segm[2*cur+1];
     //MERGING STEP
     
 }

void solve(){
    int q;
    cin>>n;
    repe(i,n)
        cin>>a[i];
    cin>>q;
    sort(a+1,a+n+1);   
    repe(i,n)
        update(1,1,n,i,a[i]); 
    repe(i,q){
        int ql,qr;
        cin>>ql>>qr;
        int l=1,r=n;
        int mid;
        int l_ind=-1,r_ind=-1;
        while(l<=r){
            mid=(l+r)>>1;
            if(a[mid]>=ql)
                r=mid-1,l_ind=mid;
            else
                l=mid+1; 
        }
        l=l_ind;
        r=n;
        while(l<=r){
            mid=(l+r)>>1;
            if(a[mid]<=qr)
                l=mid+1,r_ind=mid;
            else
                r=mid-1; 
        }
        assert(l_ind!=-1 && r_ind!=-1);
        // cout<<l_ind<<" "<<r_ind<<'\n';
        cout<<query(1,1,n,l_ind,r_ind)<<'\n';
    }
    
 
} 
 
 
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    time0 = curtime;

    int t=1;
    // cin>>t;
    repe(tt,t){
        //cout<<"Case #"<<tt<<": ";
        solve();
    }
    
    //cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;
 
}
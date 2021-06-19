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
 
 
int n;
int L[4*MX];
int R[4*MX];
vector<int>to_compress;
map<int,int>mp;
struct{
    char ty;
    int l;
    int r;
}Q[MX];
int query(int cur,int start,int end,int qs,int qe,bool isL){
     if(start>=qs && end<=qe)
         return isL?L[cur]:R[cur];
     if(start>qe || end<qs)
         return 0;          //INVALID RETURN 
     int mid=(start+end)>>1;
     int A=query(2*cur,start,mid,qs,qe,isL);
     int B=query(2*cur+1,mid+1,end,qs,qe,isL);
     //MERGING STEP
     int res=A+B;  
 
     return res;
}
void update(int cur,int start,int end,int ind,int val,bool isL){
     if(start==ind && start==end){
         //DO UPDATE
        if(isL)
            L[cur]+=val;
        else
            R[cur]+=val;
         return;
     }
     if(start>ind|| end<ind)
         return;          //OUT OF RANGE 
     int mid=(start+end)>>1;
     update(cur<<1,start,mid,ind,val,isL);
     update((cur<<1)^1,mid+1,end,ind,val,isL);
     //MERGING STEP
    if(isL)
        L[cur]=L[2*cur]+L[2*cur+1];
    else
        R[cur]=R[2*cur]+R[2*cur+1];
     
 }

 
void solve(){
  
    cin>>n;
    repe(i,n){
        cin>>Q[i].ty>>Q[i].l;
        if(Q[i].ty!='C'){
            cin>>Q[i].r;
            to_compress.pb(Q[i].l);
            to_compress.pb(Q[i].r);
        }
    }
    int cnt=1;
    int total_lines=0;
    sort(all(to_compress));
    for(auto &el:to_compress)
        if(mp[el]==0)
            mp[el]=cnt++;
    repe(i,n){
        if(Q[i].ty!='C'){
            Q[i].l=mp[Q[i].l];
            Q[i].r=mp[Q[i].r];
        }
    }
    int nax=cnt;
    assert(nax<MX);
    // update(1,1,nax,1,1,1);
    // update(1,1,nax,3,1,0);
    // cout<<query(1,1,nax,1,4,0)<<'\n';
    // cout<<query(1,1,nax,2,5,1)<<'\n';
    // return;
    vector<int>indx;
    indx.pb(0);
    repe(i,n){
        // cerr<<Q[i].ty<<" "<<Q[i].l<<" "<<Q[i].r<<'\n';
        if(Q[i].ty=='C'){
            update(1,1,nax,Q[indx[Q[i].l]].l,-1,1);
            update(1,1,nax,Q[indx[Q[i].l]].r,-1,0);
            total_lines--;
        }
        else if(Q[i].ty=='D'){
            total_lines++;
            indx.pb(i);
            update(1,1,nax,Q[i].l,1,1);
            update(1,1,nax,Q[i].r,1,0);
        }
        else{
            int res=total_lines-query(1,1,nax,1,Q[i].l-1,0)-query(1,1,nax,Q[i].r+1,nax,1);
            cout<<res<<'\n';
        }
    }
  
 
} 
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    time0 = curtime;

    int t=1;
    // cin>>t;
    repe(tt,t){
        //cout<<"Case #"<<tt<<": ";
        solve();
    }
    
    // cerr<<"Execution Time: "<<(double)timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;
 
}
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
#define MX                  100'005


auto time0 = curtime;
random_device rd;
default_random_engine generator(rd());
uniform_int_distribution<ull> distribution(0,0xFFFFFFFFFFFFFFFF);

//Is testcase present?
 
 
 
int n;
int a[MX]; 
vector<int>segm[4*MX];
void buildtree(int cur,int start,int end){
    if(start==end){
       //BASE CASE
        segm[cur].pb(a[start]);
        return;
    }
    int mid=(start+end)>>1;
    buildtree(cur<<1,start,mid);
    buildtree((cur<<1)+1,mid+1,end);
    int i=0,j=0,sz1=segm[2*cur].size(),sz2=segm[2*cur+1].size();
    while(i<sz1 && j<sz2){
        if(segm[2*cur][i]<segm[2*cur+1][j])
            segm[cur].pb(segm[2*cur][i++]);
        else
            segm[cur].pb(segm[2*cur+1][j++]);
    }
    while(i<sz1)
        segm[cur].pb(segm[2*cur][i++]);
    while(j<sz2)
        segm[cur].pb(segm[2*cur+1][j++]);
    //MERGING STEP


}
int query(int cur,int start,int end,int qs,int qe,int x,bool less){
    if(start>=qs && end<=qe){
        int ans=-1,l=0,r=segm[cur].size()-1;
        int mid;

        while(l<=r){
            mid=(l+r)>>1;
            if(less){
                if(segm[cur][mid]>x)
                    ans=mid,r=mid-1;
                else
                    l=mid+1;
            }
            else{
                if(segm[cur][mid]<x)
                    ans=mid,l=mid+1;
                else
                    r=mid-1;
            }
        }
        // if(x==3){
        //     trav(el,segm[cur])
        //         cout<<el<<" ";
        //     if(less)
        //     cout<<"-> "<<segm[cur].size()-ans;
        //     else
        //         cout<<ans;
        //     cout<<'\n';

        // }
        if(ans==-1)
            return 0;
        if(less)
            return segm[cur].size()-ans;
        else 
            return ans+1;
    }
    if(start>qe || end<qs)
        return 0;          //INVALID RETURN 
    int mid=(start+end)>>1;
    int A=query(2*cur,start,mid,qs,qe,x,less);
    int B=query(2*cur+1,mid+1,end,qs,qe,x,less);
    //MERGING STEP
    int res=A+B;  

    return res;
}


void solve(){
  
    cin>>n;
    repe(i,n)
        cin>>a[i];
    buildtree(1,1,n);
    ll ans=0;
   
    repe(i,n){
        int before=query(1,1,n,1,i,a[i],1);
        int after=query(1,1,n,i,n,a[i],0);
        // cout<<before<<" "<<after<<" "<<a[i]<<'\n';
        ans+=(ll)before*after;
    }
    cout<<ans<<'\n';
 
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
    
    //cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;
 
}
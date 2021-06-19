// AUTHOR: Sumit Prajapati
#include <bits/stdc++.h>
using namespace std;


#define ull                 unsigned long long
#define ll                  long long
#define int                  long long
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
struct{
    int a;
    int b;
    int h;
}D[MX];

int n;
int dp[MX],segm[4*MX];

int query(int cur,int start,int end,int qs,int qe){
    if(start>=qs && end<=qe)
        return segm[cur];
    if(start>qe || end<qs)
        return -1;          //INVALID RETURN 
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
        segm[cur]=val;
        return;
    }
    if(start>ind|| end<ind)
        return;          //OUT OF RANGE 
    int mid=(start+end)>>1;
    update(cur<<1,start,mid,ind,val);
    update((cur<<1)^1,mid+1,end,ind,val);
    segm[cur]=max(segm[2*cur],segm[2*cur+1]);
    //MERGING STEP
    
}
 
void solve(){

    // OP BIRRROO
    cin>>n;
    int a[5];

    repe(i,n)
        cin>>D[i].a>>D[i].b>>D[i].h;
    sort(D+1,D+n+1,[&](const auto& P,const auto& Q){
         
        if(P.b==Q.b)
            return P.a<Q.a;
        return P.b<Q.b;
    });
    int ans=0;
    for(int i=1;i<=n;i++){
        int s_r=D[i].a,ind=i;
        int l=1,r=i;
        while(l<=r){
            int mid=(l+r)>>1;
            if(D[mid].b>s_r)
                ind=mid,r=mid-1;
            else
                l=mid+1;
        }
        // cout<<i<<" "<<ind<<'\n';
        int best_here=0;
        if(ind!=i)
            best_here=query(1,1,n,ind,i-1);
        dp[i]=D[i].h+best_here;
        update(1,1,n,i,dp[i]);
        ans=max(ans,dp[i]);
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
        //cout<<"Case #"<<tt<<": ";
        solve();
    }

    //cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;

}
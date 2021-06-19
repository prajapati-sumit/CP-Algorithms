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
#define rep(i,n)            for(ll i=0;i<n;i++)
#define repe(i,n)           for(ll i=1;i<=n;i++)
#define FOR(i,a,b)          for(ll i=a;i<=b;i++)
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

ll segm[4*MX][12];

ll query(ll cur,ll start,ll end,ll qs,ll qe,ll k){
    if(qs>qe)
        return 0;
    if(start>=qs && end<=qe)
        return segm[cur][k];
    if(start>qe || end<qs)
        return 0;          //INVALID RETURN
    ll mid=(start+end)>>1;
    ll A=query(2*cur,start,mid,qs,qe,k);
    ll B=query(2*cur+1,mid+1,end,qs,qe,k);
    //MERGING STEP
    ll res=A+B;

    return res;
}
void update(ll cur,ll start,ll end,ll ind,ll val,ll k){
    if(start==ind && start==end){
        //DO UPDATE
        segm[cur][k]+=val;
        return;
    }
    if(start>ind|| end<ind)
        return;          //OUT OF RANGE
    ll mid=(start+end)>>1;
    update(cur<<1,start,mid,ind,val,k);
    update((cur<<1)^1,mid+1,end,ind,val,k);
    //MERGING STEP
    segm[cur][k]=segm[2*cur][k]+segm[2*cur+1][k];

} 

void solve(){


    ll n,k;
    cin>>n>>k;
    ll ans=0;
    repe(i,n){
        ll x;
        cin>>x;
        for(ll kk=0;kk<=k;kk++){
            ll before;
            if(kk==0){
                before=1;
                update(1,1,n,x,before,kk);
            }
            else {
                before=query(1,1,n,1,x-1,kk-1);
                update(1,1,n,x,before,kk);
            }
            if(kk==k)
                ans+=before;
            // cout<<x<<"-> "<<kk<<" "<<before<<'\n';
        }
    }
    cout<<ans<<'\n';


}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t=1;
    // cin>>t;
    repe(tt,t){
        //cout<<"Case #"<<tt<<": ";
        solve();
    }

    //cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;

}
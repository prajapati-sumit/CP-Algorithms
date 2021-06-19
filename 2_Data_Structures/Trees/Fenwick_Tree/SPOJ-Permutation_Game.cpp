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

int fact[MX];
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
    
}

void solve(){

    int n;
    cin>>n;
    int a[n+1];
    repe(i,n)
        cin>>a[i];
    int ans=0;
    memset(segm,0,sizeof(segm));
    for(int i=n;i>=1;i--){
        int indx=n-i;
        int small=query(1,1,n,1,a[i]);
        // cout<<a[i]<<" "<<small<<" "<<fact[indx]<<'\n';
        ans = ((ll)ans + (ll)fact[indx] * (small)) % MD;
        update(1,1,n,a[i],1);
    }
    ans=(ans+1)%MD;
    cout<<ans<<'\n';
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    time0 = curtime;
    fact[0]=1;
    repe(i,MX-1)
    fact[i]=((ll)i*fact[i-1])%MD;
    int t=1;
    cin>>t;
    repe(tt,t){
        //cout<<"Case #"<<tt<<": ";
        solve();
    }

    //cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;

}
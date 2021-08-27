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
const int MDL = 998244353;
const int INF = 1e9;
const int MX = 1e5 + 5;
const int p = 11;
const int MD = 1e9 + 9;
int p_pow[MX];


long long compute_hash(const vector<char>& v) {
    
    long long hash_value = 0;
    int sz=v.size();
    rep(i,sz) {
        hash_value = (hash_value + (v[i]- '0' + 1) * p_pow[i]) % MD;
    }
    return hash_value;
}

int segm[4*MX];
int n;
char a[MX];
char lazy[4*MX];
int pminus1;
ll bin_power(ll a,ll b,ll md){
    ll res=1;
    while (b){
        if (b&1)
            res=(res*a)%md;
        a=(a*a)%md;
        b>>=1;
    }
    return res;
}

void merge(int& A,int& B,int& res,int lenLeft){
    if(A==0 || B==0){
        res=A^B;
        return;
    }
    res=(A+B*p_pow[lenLeft])%MD;
}
void buildtree(int cur,int start,int end){
    if(start==end){
       //BASE CASE
        segm[cur]=a[start]-'0'+1;
        return;
    }
    int mid=(start+end)>>1;
    buildtree(cur<<1,start,mid);
    buildtree((cur<<1)+1,mid+1,end);
    //MERGING STEP
    merge(segm[2*cur],segm[2*cur+1],segm[cur],mid-start+1); 
}
void lazyUpdate(int cur,int start,int end){
    if(lazy[cur]=='!')
        return;
    char dx=lazy[cur];
    lazy[cur]='!';
    segm[cur]=(p_pow[end-start+1]+MD-1)%MD;
    segm[cur]=((dx-'0'+1)*segm[cur]*pminus1)%MD;
    if(start!=end){
        lazy[2*cur]=dx;
        lazy[2*cur+1]=dx;
    }
}
int query(int cur,int start,int end,int qs,int qe){
    lazyUpdate(cur,start,end);
    if(start>=qs && end<=qe){
        return segm[cur];
    }
    if(start>qe || end<qs)
        return 0;          //INVALID RETURN 
    int mid=(start+end)>>1;
    int A=query(2*cur,start,mid,qs,qe);
    int B=query(2*cur+1,mid+1,end,qs,qe);
    //MERGING STEP
    start=max(start,qs);
    end=min(end,qe);
    int res;
    merge(A,B,res,mid-start+1);  
    return res;
}
void update(int cur,int start,int end,int qs,int qe,char val){
    
    lazyUpdate(cur,start,end);
    if(start>=qs && end<=qe){
        lazy[cur]=val;
        lazyUpdate(cur,start,end);
        return;
    }
    if(start>qe || end<qs)
        return;          //INVALID RETURN 
    int mid=(start+end)>>1;
    update(2*cur,start,mid,qs,qe,val);
    update(2*cur+1,mid+1,end,qs,qe,val);
    //MERGING STEP
    merge(segm[2*cur],segm[2*cur+1],segm[cur],mid-start+1); 
}

void solve() {

    int m,k;
    cin>>n>>m>>k;
    repe(i,n)
        cin>>a[i];
    repe(i,4*n)
        lazy[i]='!';
    buildtree(1,1,n);
    repe(i,m+k){
        int ty,l,r,d;
        cin>>ty>>l>>r>>d;
        if(ty==1){
            update(1,1,n,l,r,char(d+'0'));
        }
        else{
            int len=r-l+1;
            int rem=len%d;
            len=len-rem;
            int repunit=query(1,1,n,l,l+d-1);
            int whole=query(1,1,n,l,l+len-1);
            bool ok=true;
            if(rem!=0){
             
                int other=query(1,1,n,l+len,l+len+rem-1);
                int pref=query(1,1,n,l,l+rem-1);
                ok=(other==pref);
            }

            // cout<<repunit<<" "<<whole<<'\n';
            repunit=(repunit*(p_pow[len]-1+MD))%MD;
            repunit=(repunit*bin_power((p_pow[d]-1+MD)%MD,MD-2,MD))%MD;
            if(ok && repunit==whole ){
                cout<<"YES\n";
            }
            else
                cout<<"NO\n";

        }
    }


}


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    time0 = curtime;
    srand(time(NULL));
    int t = 1;
    // cin >> t;
    p_pow[0]=1;
    repe(i,MX-1)
        p_pow[i]=p*p_pow[i-1]%MD;

    pminus1=bin_power(p-1,MD-2,MD);
    repe(tt, t) {
        // cout<<"Case #"<<tt<<": ";
        solve();
    }

    // cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;

}
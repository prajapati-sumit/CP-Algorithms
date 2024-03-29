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
#define MX                  200'05


auto time0 = curtime;
random_device rd;
default_random_engine generator(rd());
uniform_int_distribution<ull> distribution(0,0xFFFFFFFFFFFFFFFF);

//Is testcase present?

int segm[4*MX];
int a[MX];

 
void buildtree(int cur,int start,int end){
     if(start==end){
        segm[cur]=(a[start]==0);
        return;
     }
     int mid=(start+end)>>1;
     buildtree(cur<<1,start,mid);
     buildtree((cur<<1)+1,mid+1,end);
     //MERGING STEP
     segm[cur]=segm[2*cur]+segm[2*cur+1];

 
 
 }
 int query(int cur,int start,int end,int qs,int qe){
     if(start>=qs && end<=qe)
         return segm[cur];
     if(start>qe || end<qs)
         return 0;          //INVALID RETURN 
     int mid=(start+end)>>1;
     int A=query(2*cur,start,mid,qs,qe);
     int B=query(2*cur+1,mid+1,end,qs,qe);
     int res=A+B;                //MERGING STEP  
 
     return res;
}
int query2(int cur,int start,int end,int x){
    if(start==end){
        if(x==1 && segm[cur]==1)
            return start;
        assert(false);
    }
    int A=segm[2*cur],B=segm[2*cur+1];
    int mid=(start+end)>>1;
    if(A>=x)
        return query2(2*cur,start,mid,x);

    return query2(2*cur+1,mid+1,end,x-A);


}
void update(int cur,int start,int end,int ind){
    if(start==ind && start==end){
        segm[cur]=(a[ind]==0);
        return;

    }
    if(start>ind|| end<ind)
        return;          //OUT OF RANGE 
    int mid=(start+end)>>1;
    update(cur<<1,start,mid,ind);
    update((cur<<1)^1,mid+1,end,ind);
    //MERGING STEP
    segm[cur]=segm[2*cur]+segm[2*cur+1];
}
   
 
void solve(){
  
    int n;
    cin>>n;
    if(n==1){
        cout<<"1\n";
        return;
    }
    repe(i,n)
        a[i]=0;
    buildtree(1,1,n);
    a[2]=1;
    update(1,1,n,2);
    int cur=2;
    FOR(i,2,n){
        int req=i;
        int before=query(1,1,n,1,cur);
        int total=n-i+1;
        int indx=(i+before+1)%total;
        if(indx==0)
            indx=total;
        indx=query2(1,1,n,indx);
        a[indx]=i;
        cur=indx;
        update(1,1,n,indx);

    }
    repe(i,n)
        cout<<a[i]<<" \n"[i==n];  
  
 
} 
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    time0 = curtime;

    int t=1;
    cin>>t;
    repe(tt,t){
        //cout<<"Case #"<<tt<<": ";
        solve();
    }
    
    //cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;
 
}
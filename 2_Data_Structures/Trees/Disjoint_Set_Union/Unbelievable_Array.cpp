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
pii parent[MX];
int find_set(int x)
{
    if(parent[x].ff==x || ){}
}
bool vis[MX];
void solve(){
    
    // UNSOLVED ...!!!!
    int q;
    cin>>n>>q;
    rep(i,MX)
        parent[i]={i,0};
    repe(i,n){
        cin>>a[i];
    }
    
    repe(i,q){
        int type;
        cin>>type;
        if(type==1){
            int x,y;
            cin>>x>>y;
            parent[x]={y,i};
            
        }
        else{
            int ind;
            cin>>ind;
            int p=find_set(a[ind]);
            cout<<p<<'\n';
        }
        


}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    time0 = curtime;

    int t=1;
    cin>>t;
    repe(tt,t){
        cout<<"Case "<<tt<<":\n";
        solve();
    }

    //cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;

}
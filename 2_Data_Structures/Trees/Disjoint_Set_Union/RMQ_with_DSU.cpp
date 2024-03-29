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
struct Query{
    int l;
    int r;
    int id;
};
 
int n,q; 
int parent[MX],a[MX];
vector<Query> Q[MX] ;
int answers[MX];

int find_set(int x){
    return parent[x]==x?x:parent[x]=find_set(parent[x]);
}
void solve(){

    cin>>n;
    repe(i,n){
        cin>>a[i];
        parent[i]=i;
    }
    int q;
    cin>>q;
    repe(i,q){
        int l,r;
        cin>>l>>r;
        Q[r+1].pb({l+1,r+1,i});   
    }
    stack<int>s;
    repe(i,n){
        while (!s.empty() && a[s.top()] > a[i]) {
            parent[s.top()] = i;
            s.pop();
        }
        s.push(i);
        for (Query qq : Q[i]) {
            answers[qq.id] = a[find_set(qq.l)];
        }
    }
    repe(i,q)
        cout<<answers[i]<<endl;
 
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
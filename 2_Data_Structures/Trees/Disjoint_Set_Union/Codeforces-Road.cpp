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
vector<pii>extra;

class DSU{

    vector<int>parent;
public:
    DSU(int n){
        parent.resize(n+1);
        for(int i=1;i<=n;i++)
            parent[i]=i;
    }
    int find_set(int x){
        return parent[x]==x?x:parent[x]=find_set(parent[x]);
    } 
    void union_set(int a,int b){
        int pa=find_set(a);
        int pb=find_set(b);
        if(pa!=pb){
            parent[pb]=pa;
        }
        else
            extra.pb({a,b});
    } 
};

struct Edge{
    int a;
    int b;
};


 
void solve(){
  
    int n;        
    cin>>n;
    DSU disjoint(n);
    repe(i,n-1){
        int x,y;
        cin>>x>>y;
        disjoint.union_set(x,y);
    }
    set<int>par;
    repe(i,n)
        par.insert(disjoint.find_set(i));
    cout<<extra.size()<<endl;
    vector<int>help;
    trav(el,par)
        help.pb(el);
    rep(i,extra.size()){
        cout<<extra[i].ff<<" "<<extra[i].ss<<" "<<help[i]<<" "<<help[i+1]<<'\n';
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
    
    //cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;
 
}
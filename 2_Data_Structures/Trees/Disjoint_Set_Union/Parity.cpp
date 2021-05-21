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

//Is testcase present YES?
map<int,vector<pii>> mp;

int dfs(int cur,int par,int final,int parity){
    if(cur==final)
        return parity;
    for(auto x:mp[cur]){
        if(x.ff==par)
            continue;
        int temp=dfs(x.ff,cur,final,parity^x.ss);
        if(temp!=-1)
            return temp; 
    }
    return -1;

}

void solve(){
  
    int n;
    cin>>n;
    if(n==-1)
        exit(0); 

    mp.clear();
    int q;
    cin>>q;
    bool flag=true;
    repe(i,q){
        int x,y;
        string s;
        cin>>x>>y>>s;
        if(!flag)
            continue;
        x--;
        int can=dfs(x,-1,y,0);
        bool parity=(s=="odd");
        if(can==-1){
            mp[x].pb({y,parity});
            mp[y].pb({x,parity});
            continue;
        }
        if(can!=parity){
            cout<<(i-1)<<'\n';
            flag=false;
        }
    }
    if(flag)
        cout<<q<<endl;
} 
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    time0 = curtime;

    while(true){
        //cout<<"Case #"<<tt<<": ";
        solve();
    }
    //cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;
 
}
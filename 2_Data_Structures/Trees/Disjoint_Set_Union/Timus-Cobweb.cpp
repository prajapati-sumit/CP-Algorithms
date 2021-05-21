// AUTHOR: Sumit Prajapati      
#include <bits/stdc++.h>
using namespace std;



#define all(a)              a.begin(),a.end()
#define pb                  push_back
#define llrand()            distribution(generator)
#define rep(i,n)            for(int i=0;i<n;i++)
#define repe(i,n)           for(int i=1;i<=n;i++)

#define MX                  100'005




//Is testcase present?
 
struct Edge{
    int a;
    int b;
};
int parent[MX];
int global_ans;

int find_set(int x){
    return parent[x]==x?x:parent[x]=find_set(parent[x]);
} 

void union_set(int a,int b){
    a=find_set(a);
    b=find_set(b);
    if(a!=b){
        parent[b]=a;
        global_ans--;
    }
}
 
 
void solve(){
    
    int n,m;
    cin>>n>>m;
    global_ans=n;
    Edge edges[m+1];
    repe(i,m)
        cin>>edges[i].a>>edges[i].b;
    repe(i,n)
        parent[i]=i;
    int q;
    cin>>q;
    vector<bool> to_proces(m+1,true);
    vector<int> queries;
    repe(i,q){
        int x;
        cin>>x;
        queries.pb(x);
        to_proces[x]=false;
    }
    repe(i,m)
        if(to_proces[i])
            union_set(edges[i].a,edges[i].b);
        
    vector<int> ans;
    ans.pb(global_ans);
    reverse(all(queries));
    rep(i,q-1){
        union_set(edges[queries[i]].a,edges[queries[i]].b);
        ans.pb(global_ans);
    }
    reverse(all(ans));
    for(auto x:ans)
        cout<<x<<" ";

            
  
 
} 
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int t=1;
    // cin>>t;
    repe(tt,t){
        //cout<<"Case #"<<tt<<": ";
        solve();
    }
    
    //cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;
 
}
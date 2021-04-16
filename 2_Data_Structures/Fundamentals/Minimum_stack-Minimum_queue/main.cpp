//CODED BY SUMIT KUMAR PRAJAPATI
#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int>  pii;
typedef pair<ll, ll>  pl;

#define PI 3.1415926535897932384626
#define pb push_back
#define mk make_pair
#define ff first
#define ss second
#define trav(v) for(auto &el:v)
#define watch(x) cerr<<#x<<" = "<<x<<'\n'
#define rep(i,n) for(ll i=0;i<n;i++)
#define repe(i,n) for(ll i=1;i<=n;i++)
#define FOR(i,a,b) for(ll i=a;i<=b;i++)
#define printar(a,s,e) FOR(i,s,e)cout<<a[i]<<" ";cout<<'\n'
#define curtime chrono::high_resolution_clock::now()
#define timedif(start,end) chrono::duration_cast<chrono::nanoseconds>(end - start).count()

const int INF=1e9;
const int MX=1e5+5;
const int MD=1e9+7;
const int MDL=998244353;
auto time0 = curtime;
 
 
class minStack{

    stack< pair<int,int> >st;

    void add(int x){
        int new_min=st.empty()?x:min(x,st.top().second);
        st.push({x,new_min});
    }
    void remove(){
        if(!s.empty())
            st.pop();
    }
    int top(){
        return st.top().first;
    }
    int getmin(){
        return st.top().second;
    }
};

class minQueue{

    deque<int> q;
    int getmin(){
        return q.front();
    }
    void add(int x){
    
        while (!q.empty() && q.back() > x)
            q.pop_back();
        q.push_back(x);
    
    }
    void remove(){
        if (!q.empty() && q.front() == remove_element)
            q.pop_front();
    }

};
 
 
 
void solve(){


        
  
 
} 
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    srand(time(0)); 
    time0 = curtime;

    ll t=1;
    //cin>>t;
    repe(tt,t){
        //cout<<"Case #"<<tt<<": ";
        solve();
    }
    
    //cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;
 
}
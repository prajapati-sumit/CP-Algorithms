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
 
 
 
 
ll n,queries;
ll mat[21][21];
ll temp[21][21];
string s;
ll a,b;
stack<string>stack1,stack2;
void add(){
    if(q.empty()){
        q.push_back(s);
        repe(i,n){
            mat[i][i]=1;
        }
        return;
    }
    string tp=q.back();
    q.push_back(s);
    repe(i,n){
        repe(j,n){
            temp[i][j]=0;

            if(j-1>0 && tp[j-2]==s[j-1])
                temp[i][j]=(temp[i][j]+mat[i][j-1])%MD;
            if(j+1<=n && tp[j]==s[j-1])
                temp[i][j]=(temp[i][j]+mat[i][j+1])%MD;
            if(s[j-1]==tp[j-1])
                temp[i][j]=(temp[i][j]+mat[i][j])%MD;
        }
    }
    repe(i,n){
        repe(j,n){
            mat[i][j]=temp[i][j];
            cout<<mat[i][j]<<" ";
        }
        cout<<'\n';
    }
    cout<<'\n';
}
void remove(){
   
    s=q.front();
    q.pop_front();
    string tp=q.front();
    repe(i,n){
        repe(j,n){
            temp[i][j]=0;
            if(j-1>0 && s[j-2]==tp[j-1])
                temp[i][j]=(temp[i][j]+MD-mat[i][j-1])%MD;
            if(j+1<=n && s[j]==tp[j-1])
                temp[i][j]=(temp[i][j]+MD-mat[i][j+1])%MD;
            if(s[j-1]==tp[j-1])
                temp[i][j]=(temp[i][j]+MD-mat[i][j])%MD;
        }
    }
    repe(i,n){
        repe(j,n){
            mat[i][j]=temp[i][j];
            cout<<mat[i][j]<<" ";
        }
        cout<<'\n';
    }
    cout<<'\n';
}
void solve(){
  
    //I Can't Do it :(
    cin>>n>>queries;  
    string type;
    
    repe(i,queries){
        cin>>type;
        if(type=="add"){
            cin>>s;
            add();
        }
        else if(type=="remove"){
            remove();
        }
        else{
            cin>>a>>b;
            cout<<mat[a][b]<<'\n';
        }
    }  
 
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
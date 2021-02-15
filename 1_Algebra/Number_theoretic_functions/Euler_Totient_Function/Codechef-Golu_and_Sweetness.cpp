#include <bits/stdc++.h>
using namespace std;
 
//CODED BY SUMIT KUMAR PRAJAPATI
typedef unsigned long long ull;
typedef long long vll;
typedef pair<int, int>  pii;
typedef pair<vll, vll>  pl;

#define si(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)
#define ss(s) scanf("%s",s)
#define pi(x) printf("%d\n",x)
#define pl(x) printf("%lld\n",x)
#define ps(s) printf("%s\n",s)
#define PI 3.1415926535897932384626
#define pb push_back
#define mk make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define rep(i,n) for(vll i=0;i<n;i++)
#define repe(i,n) for(vll i=1;i<=n;i++)
#define FOR(i,a,b) for(vll i=a;i<=b;i++)
#define printar(a,s,e) FOR(i,s,e)cout<<a[i]<<" ";cout<<'\n'
#define curtime chrono::high_resolution_clock::now()
#define timedif(start,end) chrono::duration_cast<chrono::nanoseconds>(end - start).count()
const int MX=1e5+5;
const int MD=1e9+7;
const int MDL=99824453;
auto time0 = curtime;
 
 




 
void solve(){
    

    vll n,q;
    cin>>n>>q;
    vll a[n+1];
    repe(i,n){
        cin>>a[i];
        a[i]=(a[i]==3 || a[i]==4 || a[i]==6);
    }
    a[0]=0;
    repe(i,n)
        a[i]+=a[i-1];
    while(q--){
        vll l,r;
        cin>>l>>r;
        vll ans=a[r]-a[l-1];
        cout<<ans<<'\n';
    } 
} 

 
 
int main() {

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #else
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    #endif

    srand(time(0)); 

    time0 = curtime;
    vll t=1;
    
    while(t--)
        solve();
    
    auto timeend=curtime;
    auto extime=timedif(time0,timeend)*1e-9;
    cerr<<"Execution Time: "<<extime<<" sec\n";
    return 0;
 
}
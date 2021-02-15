#include <bits/stdc++.h>
using namespace std;
 
//CODED BY SUMIT KUMAR PRAJAPATI
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int>	pii;
typedef pair<ll, ll>	pl;

#define si(x)	scanf("%d",&x)
#define sl(x)	scanf("%lld",&x)
#define ss(s)	scanf("%s",s)
#define pi(x)	printf("%d\n",x)
#define pl(x)	printf("%lld\n",x)
#define ps(s)	printf("%s\n",s)
#define PI 3.1415926535897932384626
#define pb push_back
#define mk make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define rep(i,n) for(ll i=0;i<n;i++)
#define repe(i,n) for(ll i=1;i<=n;i++)
#define FOR(i,a,b) for(ll i=a;i<=b;i++)
#define curtime chrono::high_resolution_clock::now()
#define timedif(start,end) chrono::duration_cast<chrono::nanoseconds>(end - start).count()
const int MX=1e6+5;
const int MD=1e9+7;
const int MDL=99824453;
auto time0 = curtime;
 
 
vector<int>primes(MX,0); 
int res[11][MX];
 
 
void solve(){
 
    int a,b,n;
    cin>>a>>b>>n;
    if(n==0)
    {
        if(a==1)
            cout<<"1\n";
        else 
            cout<<"0\n";
        return;
    }
    cout<<res[n][b]-res[n][a-1]<<"\n";

 
} 
void init(){
    for(int i=2;i<MX;i++){
        if(primes[i]==0){
            for(int j=2*i;j<MX;j+=i)
                primes[j]++;
        }
    }
    FOR(i,2,MX-2){
        int cur=primes[i];
        if(cur==0)
            cur=1;
        res[cur][i]=1;
        rep(j,11)
            res[j][i]+=res[j][i-1];
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
    ll t=1;
    cin>>t;
    init();
    while(t--)
        solve();
 
    return 0;
 
}

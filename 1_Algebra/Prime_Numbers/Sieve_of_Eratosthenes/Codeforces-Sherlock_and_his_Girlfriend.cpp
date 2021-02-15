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
const int MX=1e5+5;
const int MD=1e9+7;
const int MDL=99824453;
auto time0 = curtime;
 
int ar[MX]; 
int lp[MX]; 
int ans[MX];

void init(){

    
    rep(i,MX)
        lp[i]=i;

    int sq=sqrt(MX);
    FOR(i,2,sq)
        if(lp[i]==i)
        {
            for(int j=i*i;j<MX;j+=i)
                if(lp[j]==j)
                    lp[j]=i;
        }
    ans[0]=0;
    FOR(i,1,MX-1)
    {
        if(lp[i]==i)
            ar[i]=1;
        else
            ar[i]=ar[i/lp[i]]+1;

        ans[i]=max(ans[i-1],ar[i]);
    }
        

} 

 
void solve(){
    
    //QUESTION WAS WRONG
    
    int n;
    cin>>n;
    
    cout<<ans[n+1]<<"\n";
    FOR(i,2,n+1)
        cout<<ar[i]<<" ";
    cout<<'\n';
 
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
    //cin>>t;
    init();
    while(t--)
        solve();
 
    return 0;
 
}

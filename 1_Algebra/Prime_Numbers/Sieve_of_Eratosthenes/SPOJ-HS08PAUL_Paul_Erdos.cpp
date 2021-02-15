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
const int MX=1e7+1;
const int MD=1e9+7;
const int MDL=99824453;
auto time0 = curtime;

int res[MX];
vector<bool>isPrime(MX,true); 


void init(){


    int n=MX-1;
    
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i)
                isPrime[j] = false;
        }
    }
    int sq=sqrt(MX);
    int sq4=sqrt(sq);
    repe(i,sq){
        repe(j,sq4){
            int p=i*i+j*j*j*j;
            if(p<MX && isPrime[p])
                res[p]=1;
        }
       
    }
    repe(i,MX){
        res[i]+=res[i-1];
    }
} 
void solve(){
 
    int n;
    cin>>n;
    cout<<res[n]<<'\n';
 
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

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
const int MX=3162;
const int MD=1e9+7;
const int MDL=99824453;
auto time0 = curtime;
const int MAX_N=1e6+5;
vector<bool>isPrime(MAX_N,true);
map<int,int>mpprime;




void init(){

//SIMPLE SIEVE
    
    isPrime[0] = false;
    isPrime[1] = false;
    for (int i = 2; i * i <= MAX_N-1; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= MAX_N-1; j += i)
                isPrime[j] = false;
        }
    }
    int indx=1;
    rep(i,MAX_N-1)
        if(isPrime[i])
            mpprime[i]=indx++;



}
 
 
 
 
void solve(){
 
    //TIME LIMIT EXCEEDED (CAN'T OPTIMISE)
    int n;
    cin>>n;
    auto it =mpprime.find(n);
    if(it==mpprime.end())
        cout<<"-1\n";
    else{
        n=it->second;
        //cout<<n<<" ";
        int D=sqrt(1+8*n);
        D--;
        D/=2;
        int C=n-(D*(D+1))/2;
        if(C!=0)
            D++;
        else
            C=D;
        cout<<D<<" "<<C<<'\n';
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
    cerr<<"Ex Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;
 
}

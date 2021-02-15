#include <bits/stdc++.h>
using namespace std;
 
//CODED BY SUMIT KUMAR PRAJAPATI
// typedef unsigned long long vll;
typedef long long vll;

typedef pair<int, int>  pii;
typedef pair<vll, vll>  pl;


#define rep(i,n) for(vll i=0;i<n;i++)
#define repe(i,n) for(vll i=1;i<=n;i++)
#define FOR(i,a,b) for(vll i=a;i<=b;i++)
 

map<vll,vll>factors;
vll N=1;
vll bases[]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227};


void fastscan(vll &x)
{
       
    register int c;
    x =0;
    c=getchar();
    
    for(;(c>47 && c<58);c=getchar())
        x = (x<<1) + (x<<3) +c -48;
        
}

vll bin_power(vll a,vll b,vll md){
    vll res=1;
    a%=md;
    while(b){
        if(b&1)
            res=(res*a)%md;
        a=(a*a)%md;
        b>>=1;
    }
    return res;
}

bool check_composite(vll a,vll d,vll s,vll n){
    
    vll x=bin_power(a,d,n);
    if (x==1 || x==n-1)
        return false;

    rep(i,s-1){
        x=(x*x)%n;
        if(x==n-1)
            return false;
    }
    return true;
}
bool is_prime_miller_rabin(vll n){

    
    vll d=n^1;
    vll s=0;
    while(d%2==0)
    { 
        s+=1;
        d>>=1;
    }
    for(auto a :bases){
        if (n==a)
            return true;
        if (check_composite(a,d,s,n))
            return false;
    }
    return true;
}

vll pollard_p_minus_1(vll x){
    vll limit=vll(1e6);
    vll a=2;
    vll aB=2;
    FOR(B,2,limit){
        vll g=__gcd(aB-1,x);
        if (g!=1 && g!=x)
            return min(g,x/g);

        aB=bin_power(aB,B,x);
    }

    return x ;
}

void factorise(vll n){
    
    
    if(n==1)
        return;

    if(is_prime_miller_rabin(n)){
        factors[n]=1;
        return;
    }
    //cout<<n<<"\n";
    //return;
    vll f=pollard_p_minus_1(n);
    
    
    assert(f!=n);
    if (is_prime_miller_rabin(f)){
        int cnt=0;
        while(n%f==0){
            cnt+=1;
            n/=f;
        }
        factors[f]=cnt;
        factorise(n);
    }
    else
        factorise(f);
        

}   


 
 
void solve(){
    
    factors.clear();
    for(auto x:bases){
        if (N%x==0){
            int cnt=0;
            while(N%x==0){
                cnt+=1;
                N/=x;
            }
            factors[x]=cnt;
        }
    }
    
    factorise(N);
    vll ans=1;
    for(auto f:factors)
        ans*=(f.second+1);
    
    cout<<ans<<'\n';
 
} 
 
 
int main() {
   
   

    
    
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    // cin>>N;
    cerr<<N<<"\n";
    solve();
    
    return 0;
 
}
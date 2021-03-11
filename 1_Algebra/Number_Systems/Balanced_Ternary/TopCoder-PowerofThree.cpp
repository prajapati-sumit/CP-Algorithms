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
const int MDL=99824453;
auto time0 = curtime;
 
class PowerOfThree{

    
    public:
        vector<char> convert(int x){
            bool isneg=false;
            if(x<0){
                isneg=true;
                x=-x;
            }
            vector<char>v;
            while(x){
                int rem=x%3;
                v.push_back(char(rem+'0'));
                x/=3;
            }
            int carry=0;
            for(int i=0;i<v.size();i++){
                v[i]=char(v[i]+carry);
                if(v[i]=='3'){
                    v[i]='0';
                    carry=1;
                }
                else if(v[i]=='2'){
                    v[i]='z';
                    carry=1;
                }
            }
            if(carry)
                v.push_back('1');
            if(isneg){
                for(int i=0;i<v.size();i++)
                    if(v[i]=='1')
                        v[i]='z';
                    else if(v[i]=='z')
                        v[i]='1';
            }
            
            return v;
        } 
        string ableToGet(int x,int y){
            vector<char> s1=convert(x),s2=convert(y);
            int sz=max(s1.size(),s2.size());
            
            while(s1.size()<sz)
                s1.pb('0');
            while(s2.size()<sz)
                s2.pb('0');
            for(int i=0;i<sz;i++){
                if((s1[i]!='0' && s2[i]!='0') || (s1[i]=='0' && s2[i]=='0')){
                    return "Impossible";
                    
                }

            }
            return "Possible";

        }
};

 
 
void solve(){
    //No place to submit.Good use of Balanced Ternary.
    PowerOfThree P;
    cout<<P.ableToGet(1,9);
    
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
    
    cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;
 
}
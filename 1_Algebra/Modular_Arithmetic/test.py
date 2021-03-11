from math import gcd
MD=int(1000000007)
def bin_power(a,b,md):
    res=1
    while b:
        if b&1:
            res=(res*a)%md
        a=(a*a)%md
        b>>=1
    return res

def lcm(x,y):
    res=(x*y)%MD
    res=(res*bin_power(gcd(x,y),MD-2,MD))%MD
    return res
def lcmraw(x,y):
    return (x*y)//gcd(x,y)

ans=1
res=1
for i in range(1,100):
    res=lcm(res,i)
for i in range(1,100):
    ans=lcmraw(ans,i)
print(ans,ans%MD,res)
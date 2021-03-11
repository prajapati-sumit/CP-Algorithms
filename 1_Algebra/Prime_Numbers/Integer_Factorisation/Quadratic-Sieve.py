# CODED BY SUMIT KUMAR PRAJAPATI
import os
import io
import sys
import math

MD=int(1e9+7)
MX=int(1e5+2)
pi=3.1415926535897932


def intinp():
    return int(input())

def arinput():
    return list(map(int,input().strip().split()))

def fast_io(): 
    input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline

def io_file():
    sys.stdin=open("input.txt",'r')
    sys.stdout=open("output.txt",'w')


bases=[2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47]
def bin_power(a,b,md):
    res=1
    a%=md
    while b:
        if b&1:
            res=(res*a)%md
        a=(a*a)%md
        b>>=1
 
    return res
 
def check_composite(a,d,s,n):
    
    x=bin_power(a,d,n)
    if x==1 or x==n-1:
        return False
 
    for i in range(s-1):
        x=(x*x)%n
        if x==n-1:
            return False
 
    return True
 
def is_prime_miller_rabin(n):
 
    
    d=n-1;
    s=0;
    while d&1==0:
        s+=1
        d>>=1
    
    for a in bases:
        if n==a:
            return True
        if check_composite(a,d,s,n):
            return False
 
    return True
 

 
def quadratic_sieve(n): 
    sqn=int(math.sqrt(n))+1
    lst=[]
    for i in range(100):
        lst.append((sqn+i,((sqn+i)*(sqn+i))%n))
    for i in range(100):
        for j in range(i+1,100):
            rhs=lst[i][1]*lst[j][1]
            root=int(math.sqrt(rhs))
            if root*root==rhs:
                lhs=lst[i][0]*lst[j][0]
                g=math.gcd(abs(lhs-root),n)
                if g!=1 and g!=n:
                    return g
    assert(1==0)

 
def solve():  
    
    # n = 720720
    n=int(input())
    if n==0:
       exit()
    if n==1:
        print()
        return
    
    num = n 
    
    ans={} 
    
    cnt=0
    if num%2==0:
        while num%2==0:
            num//=2
            cnt+=1
        ans[2]=cnt
    
    while(True):
        if num==1:
            break
        
        if(is_prime_miller_rabin(num)): 
            ans[num]=1
            break
 
        
        
        d=quadratic_sieve(num)
        while not is_prime_miller_rabin(d):
            d=quadratic_sieve(d) 
        # print(d)
        cnt=0
        while num%d==0:
            num//=d
            cnt+=1
        ans[d]=cnt 
    
        
  
    ans=dict(sorted(ans.items()))
    #print(ans)
    for p,pw in ans.items():
        # res*=(normalpower(p,pw+1)-1)//(p-1)
        print(f"{p}^{pw}",end=" ")
    print()
 




if __name__=='__main__':
    fast_io()
    io_file()
    tc=1
    # tc=intinp()
    while True:
        # print(f"Case #{t}: ",end='')
        solve()



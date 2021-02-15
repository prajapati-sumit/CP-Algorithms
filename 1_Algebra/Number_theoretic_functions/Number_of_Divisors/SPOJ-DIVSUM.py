import math 
import random
import collections
 
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
 
      
def f(x,c):
    return x*x+c
 
def pollardrho(n): 
   
    a = random.randint(2, n) 
    b=a
    p=1
    c=random.randint(2,n-1)
    while p==1 :
        #a runs once
        a = f(a,c)%n
        #b runs twice as fast.
        b = f(f(b,c),c)%n
        
        p = math.gcd( abs(b - a) , n)
        if a==b:
            #print("Can't factor",n)
            a = random.randint(2, n) 
            b=a
            c=random.randint(2,n-1)
           #exit()
    return p    
    
 
def normalpower(a,b):
    res=1
    while b:
        if b&1:
            res=(res*a)
        a=(a*a)
        b>>=1
    return res
 
 
def solve():  
    # Driver code 
    n = 2432902008176640000
    # n=int(input())
    if n==0:
       exit()
    if n==1:
        print()
        return
    # temporarily storing n
    num = n 
    # list for storing prime factors 
    ans={} 
    
    cnt=0
    if num%2==0:
        while num%2==0:
            num//=2
            cnt+=1
        ans[2]=cnt
    
    
    
    
    print(num)   
    # iterated till all prime factors 
    # are obtained 
    while(True):
        if num==1:
            break
        # check for prime using sympy 
        if(is_prime_miller_rabin(num)): 
            # both prime factors obtained 
            #print(num,"!")
            ans[num]=1
            break
 
        
        # function call 
        d=pollardrho(num)
        while not is_prime_miller_rabin(d):
            d=pollardrho(d) 
        print(d)
        cnt=0
        while num%d==0:
            num//=d
            cnt+=1
        ans[d]=cnt 
    
        
            
        
       
        
 
 
    res=1
    ans=dict(sorted(ans.items()))
    #ans= collections.OrderedDict(sorted(ans.items()))
    #print(ans)
    for p,pw in ans.items():
        res*=(normalpower(p,pw+1)-1)//(p-1)
        print(f"{p}^{pw}",end=" ")
    res-=n         
    print(res)
    print()
 
if __name__=='__main__':
    # a=int(1e7+9)
    # print(a*a)
    solve()
    exit()
    while True:
        solve()
 
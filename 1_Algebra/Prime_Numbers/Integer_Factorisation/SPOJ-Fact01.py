import math
import collections
import random
import sys
#GOOD FOR N<=10^19
# sys.stdout = open("./input.txt","r")
# sys.stdout = open("./output.txt","w")

factors={}

bases=[2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227]

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

def pollard_p_minus_1(x):
    limit=int(1e6+7e5)
    a=2
    aB=2
    for B in range(2,limit):
        g=math.gcd(aB-1,x)
        if g!=1 and g!=x:
            return min(g,x//g)

        aB=bin_power(aB,B,x)

    return x 

def factorise(n):

    if n==1:
        return
    if is_prime_miller_rabin(n):
        factors[n]=1
        return
    f=pollard_p_minus_1(n)
    assert(f!=n) 
    if is_prime_miller_rabin(f):
        cnt=0
        while n%f==0:
            cnt+=1
            n//=f
        factors[f]=cnt
        factorise(n)
    else:
        factorise(f)
        

    


if __name__=="__main__":
    
    while True:
        N=int(input())
        
        
        if N==0:
            break
        
        #print(N)
        factors.clear()
        for x in bases:
            if N%x==0:
                cnt=0
                while N%x==0:
                    cnt+=1
                    N//=x
                factors[x]=cnt

        factorise(N)
        factors=collections.OrderedDict(sorted(factors.items()))
        for f in factors:
            print(f,"^",factors[f],sep="",end=" ")
        print()
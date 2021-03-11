# CODED BY SUMIT KUMAR PRAJAPATI
import os
import io
import sys
import math

MD=int(1e9+7)
MX=int(1e6+2)
pi=3.1415926535897932

cnt=0
def intinp():
    return int(input())

def arinput():
    return list(map(int,input().strip().split()))


def f(one,two,three):
    global cnt
    if one==0 and two==0 and three==0:
        cnt+=1
    if one>0:
       f(one-1,two,three)
    if two>0:
        if two>1: 
            f(one,two-1,three)
        elif two==1 and one==0:
            f(one,two-1,three)
    if three>0:
        if three>1:
            f(one,two,three-1)
        elif three==1 and two==0:
            f(one,two,three-1)


fact=[] 
def bin_power(a,b,md):
    res=1
    while b:
        if b&1:
            res=(res*a)%md
        a=(a*a)%md 
        b>>=1
    return res

def modInverse(x):
    return bin_power(x,MD-2,MD)

def ncr(n,r):
    return (fact[n]* modInverse(fact[r]) % MD * modInverse(fact[n-r]) % MD) % MD

def solve():
    f(3,3,3)
    print(cnt)
    n=intinp()
    a=arinput()
    pref=[a[0]]
    for i in range(1,n):
        pref.append(pref[-1]+a[i])
    ans=1
    for i in range(1,n):
        cur=0
        for j in range(1,a[i]):
            cur+=ncr(pref[i-1]+1,j)
        # print(cur,end=" ")
        ans=ans*cur
    print(ans)




def io_file():
    sys.stdin=open("input.txt",'r')
    sys.stdout=open("output.txt",'w')



if __name__=='__main__':
   
    io_file()
    tc=1
    tc=intinp()
    cnt=0
    fact.append(1)
    for i in range(1,MX):
        fact.append((i*fact[-1])%MD)
    for t in range(1,tc+1):
        print(f"Case {t}: ",end='')
        solve()


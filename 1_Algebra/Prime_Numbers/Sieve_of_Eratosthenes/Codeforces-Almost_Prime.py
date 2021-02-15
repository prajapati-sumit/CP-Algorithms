
n_div=[0]*3005
def sieve():
    n_div[1]=0
    for i in range(2,3002):
        if n_div[i]==0:
            for j in range(i,3002,i):
                n_div[j]+=1
    





sieve()
n=int(input())
res=0
cnt=0
for i in range(1,n+1):
    if n_div[i]==2:
        cnt+=1
        


print(cnt)
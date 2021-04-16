
def fasfn(a,target):

    if target==0:
        print(res)

    for x in a:
        if x<=target:
            res.append(x)
            fn(a, target-x)
            res.pop()


def fn(x):
    if x==1:
        return 1
    if x%6==0:
        return fn(x//2)+fn(x//3)+fn(x-1)
    if x%3==0:
        return fn(x//3)+fn(x-1)
    if x%2==0:
        return fn(x//2)+fn(x-1)
    return fn(x-1)
res=[]
def find(st,pat,ind,cur):
    if cur>=len(st):
        return
    if cur-ind+1>=len(pat):
        res.append(ind)
        find(st, pat, ind+1, ind+1)
        return
    if st[cur]==pat[cur-ind]:
        find(st,pat,ind,cur+1)
    else:
        find(st,pat,cur+1,cur+1)

st="largepatternandsmallpattern"
pat="pattern"
find(st,pat,0,0)
print(res)


MD=1e9+7

def fib(n):
	if n==0:
		return (0,1)
	
	cur=fib(n>>1)
	nth=(cur[0]*((2*cur[1]+MD-cur[0])%MD))%MD
	nth1=((cur[0]*cur[0])%MD+(cur[1]*cur[1])%MD)%MD
	if n&1:
		return (nth1,(nth+nth1)%MD)
	return (nth,nth1)



n=int(input().strip())
print(fib(n))
	
 
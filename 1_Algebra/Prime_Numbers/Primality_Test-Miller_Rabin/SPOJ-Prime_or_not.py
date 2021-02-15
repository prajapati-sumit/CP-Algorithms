


#9*6 mod 5
#9*6=(9+9+9+9)+(9+9)+(_) {6=110}
def mulmod(a,b,md):
	res=0
	while b:
		if b&1:
			res=(res+a)%md
		a=(a+a)%md
		b>>=1

	return res




def bin_power(a,b,md):
	res=1
	a%=md
	while b:
		if b&1:
			res=mulmod(res,a,md)
		a=mulmod(a,a,md)
		b>>=1

	return res


def check_composite(a,d,s,n):
	
	x=bin_power(a,d,n)
	if x==1 or x==n-1:
		return False

	for i in range(s-1):
		x=mulmod(x,x,n)
		if x==n-1:
			return False

	return True




def is_prime_miller_rabin(n):

	d=n-1;
	s=0;
	while d&1==0:
		s+=1
		d>>=1
	bases=[2,3,5,7,11,13,17,19,23,29,31,37,41]
	for a in bases:
		if n==a:
			return True
		if check_composite(a,d,s,n):
			return False

	return True



if __name__=='__main__':
	for t in range(int(input())):
		n=int(input())
		if is_prime_miller_rabin(n):
			print("YES")
		else:
			print("NO")
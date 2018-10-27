def fact(n,k):
	i=1
	f=1
	g=1
	h=1
	while i<=n:
		f=f*i
		i=i+1
	i=1
	while i<=(n-k):
		g=g*i
		i=i+1
	i=1
	while i<=k:
		h=h*i
		i=i+1
	return f/(g*h)
		
x=raw_input()
y=x.split(' ')
N=int(y[0])
W=int(y[1])
T=int(y[2])
R=int(y[3])
print (fact(N,W)*fact(N-W,T))%1000000007

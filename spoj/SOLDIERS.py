t=input()

for i in range (0,t):
	s=raw_input()
	str=s.split(' ')
	b=int(str[0])
	c=int(str[1])
	if b%2:
             m=b/2+1
	else:
	     m=b/2
	if c%2:
	     n=c/2+1
	else:
	     n=c/2
	ans1=b*n
	ans2=c*m
	if ans1>ans2:
	     ans=ans1
	else:
	     ans=ans2
	print ans
    

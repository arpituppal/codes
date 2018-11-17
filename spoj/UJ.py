while 1:
	s=raw_input()
	str=s.split(' ')
	c=int(str[0])
	d=int(str[1])
	if c==0:
		if d==0:
		  break;
	x=1;
	s=1
	while x<=d:
	  s=s*c
	  x=x+1
	print s
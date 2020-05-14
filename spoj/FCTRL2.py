def fact(a):
 if a==0:
  return 1
 else:
  return a*fact(a-1)

t=input()
x=1
while x<=t:
 n=input()
 f=fact(n)
 x=x+1
 print f

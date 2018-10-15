while True:
  try:
    n=input()
  except EOFError:
    break;
  if n==0:
     d=0
  elif n==1:
    d=1
  else:
    d=(2*n)-2
  print d

def computeGCD(x, y):
 
   while(y):
       x, y = y, x % y
 
   return x

mod = 1000000007
t = input()
t = int(t)

i = 1
while i<=t:
	a,b,n = input().split()
	a = int(a)
	b = int(b)
	n = int(n)  
	if(a-b == 0):
		first = pow(a,n,mod)
		second = pow(b,n,mod)
		z = (first+second)%mod
		print(z)
	else:	 
		first = pow(a,n,a-b);
		second = pow(b,n,a-b) 
		z = (first + second)%(a-b) ;
		print(computeGCD(z,a-b)%mod);

	i = i + 1	

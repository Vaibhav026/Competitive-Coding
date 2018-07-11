

int arr = {25,50,3*f,2*f,f};

sort(arr,arr+5);

int ans = arr[4] + arr[3] + arr[2];

return ans;



for(int i= 0;i<F;i++)
	a[i] = i+1;

int siz2 = 2*F;
for(int i= F;i<siz2;i++)
	a[i] = 2*(i+1-F);

int siz3 = 3*F;

for(int i= siz2;i<siz3;i++)
	a[i] = 3*(i+1-siz2);

a[siz3] = 25;
a[siz3+1] = 50;

sort(a,a+n);

ans = a[n-1] + a[n-2] + a[n-3]
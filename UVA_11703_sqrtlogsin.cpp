#include <stdio.h>
#include <math.h>

long long result[1000010];
int main()
{
	long long input, i, x, y, z;
	result[0] = 1;
	for(i=1; i<=1000000; i++)
	{
		x = floor(i - sqrt(i));
		y = floor(log(i));
		z = floor(i * sin(i) * sin(i));
		result[i] = (result[x]%1000000+result[y]%1000000+result[z]%1000000)%1000000;
	}
	scanf("%lld",&input);
	while(input != -1)
	{
		printf("%lld\n", result[input]);
		scanf("%lld",&input);
	}
	return 0;
}

#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int main()
{
	long long N, R, result, i;
	long double temp;
	while(scanf("%lld %lld",&N,&R) != EOF)
	{
		temp = 0;
		for(i=0; i<R; i++)
		{
			temp = temp + log10(N-i) - log10(R-i);
		}
		result = ceil(temp);
		if(result - temp <= 1e-9)
		{
			printf("%lld\n", result+1);	
		}
		else
		{
			printf("%lld\n", result);
		}
	}
}

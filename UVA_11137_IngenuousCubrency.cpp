#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <vector>
#include <math.h>
using namespace std;

long long dp[25][10100], value[25], N, maxx;
long long solve(long long type, long long remN)
{
	long long ways=0;
	if(remN == 0) return 1;
	if(type == maxx) return 0;
	if(dp[type][remN] != -1) return dp[type][remN];
	
	ways += solve(type+1, remN);
	if(remN - value[type] >= 0)
		ways += solve(type, remN-value[type]);
	return dp[type][remN] = ways;
}
int main()
{
	long long temp;
	int i;
	for(i=0; i<21; i++)
	{
		value[i] = (i+1)*(i+1)*(i+1);
	}
	memset(dp, -1, sizeof(dp));
	while(scanf("%lld",&N) != EOF)
	{
		for(maxx=0; maxx<21; maxx++)
		{
			if(value[i] > N)
			{
				break;
			}
		}
		temp = solve(0, N);
		printf("%lld\n", temp, N); 
	}
	return 0;
}

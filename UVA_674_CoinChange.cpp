#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <vector>
using namespace std;

long long dp[5][30100], value[5], N;
long long solve(long long type, long long remN)
{
	long long ways=0;
	if(remN == 0) return 1;
	if(type == 5) return 0;
	if(dp[type][remN] != -1) return dp[type][remN];
	
	ways += solve(type+1, remN);
	if(remN - value[type] >= 0)
		ways += solve(type, remN-value[type]);
	return dp[type][remN] = ways;
}
int main()
{
	long long temp;
	value[0] = 1;
	value[1] = 5;
	value[2] = 10;
	value[3] = 25;
	value[4] = 50;
	memset(dp, -1, sizeof(dp));
	while(scanf("%lld",&N) != EOF)
	{
		//memset(dp, -1, sizeof(dp));
		temp = solve(0, N);
		printf("%lld\n", temp);
	}
	return 0;
}

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>
using namespace std;

int N, K;
long long dp[110][110];
long long solve(int NRemaining, int KRemaining)
{
	long long ways=0;
	int i;
	if(KRemaining == 1)
	{
		return 1;
	}
	if(dp[NRemaining][KRemaining] != -1)
	{
		return dp[NRemaining][KRemaining];
	} 
	for(i=0; i<=NRemaining; i++)
	{
		ways += (solve(NRemaining-i, KRemaining-1)) % 1000000;
	}
	return dp[NRemaining][KRemaining] = ways % 1000000;
}
int main()
{
	scanf("%d %d",&N,&K);
	while(N != 0 || K != 0)
	{
		memset(dp, -1, sizeof(dp));
		printf("%lld\n", solve(N, K));
		scanf("%d %d",&N,&K);
	}
	return 0;
}

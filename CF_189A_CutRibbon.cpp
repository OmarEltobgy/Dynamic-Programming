#include <stdio.h>
#include <algorithm>
#include <math.h>
using namespace std;

int n, a, b, c, dp[4020];
int solve(int nRemaining)
{
	if(nRemaining < 0)
	{
		return -5000;
	}
	if(nRemaining == 0)
	{
		return 0;
	}
	if(dp[nRemaining] != -1)
	{
		return dp[nRemaining];
	}
	int takeA = 1 + solve(nRemaining - a);
	int takeB = 1 + solve(nRemaining - b);
	int takeC = 1 + solve(nRemaining - c);
	return dp[nRemaining] = max(takeA, max(takeB, takeC));
}
int main()
{
	int i, result;
	scanf("%d %d %d %d",&n,&a,&b,&c);
	for(i=0; i<=n; i++)
	{
		dp[i] = -1;
	}
	result = solve(n);
	printf("%d", result);
	return 0;
}

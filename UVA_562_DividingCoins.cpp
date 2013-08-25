#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;

int coins[300], coinsN, dp[300][50050], totalSum;
int solve(int index, int firstSum)
{
	if(index == coinsN)
	{
		return abs(firstSum - (totalSum-firstSum));
	}
	if(dp[index][firstSum] != -1)
	{
		return dp[index][firstSum];
	}
	int first = solve(index+1, firstSum+coins[index]);
	int second = solve(index+1, firstSum);
	return dp[index][firstSum] = min(first, second);
}
int main()
{
	int testsN, i, j, k;
	scanf("%d",&testsN);
	while(testsN--)
	{
		scanf("%d",&coinsN);
		totalSum = 0;
		for(i=0; i<coinsN; i++)
		{
			scanf("%d",&coins[i]);
			totalSum += coins[i];
		}
		for(i=0; i<coinsN; i++)
		{
			for(j=0; j<=totalSum; j++)
			{
				dp[i][j] = -1;
			}
		}
		printf("%d\n", solve(0, 0));
	}
	return 0;
}

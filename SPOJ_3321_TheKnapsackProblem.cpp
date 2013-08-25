#include <stdio.h>
#include <algorithm>
#include <math.h>
using namespace std;

int items[3000][2], maxSize, dp[3000][3000], itemsN;
int solve(int index, int size)
{
	int take=0, leave=0;
	if(size == maxSize)
	{
		return 0;
	}
	if(index == itemsN)
	{
		if(size <= maxSize)
		{
			return 0;
		}
		else
		{
			return -1000000;
		}
	}
	if(dp[index][size] != -1)
	{
		return dp[index][size];
	}
	if(size+items[index][0] <= maxSize)
	{
		take = items[index][1] + solve(index+1, size+items[index][0]);
	}
	leave = solve(index+1, size);
	return dp[index][size] = max(take, leave);
}
int main()
{
	int i, j;
	scanf("%d %d",&maxSize,&itemsN);
	for(i=0; i<itemsN; i++)
	{
		scanf("%d %d",&items[i][0],&items[i][1]);
		for(j=0; j<=maxSize; j++)
		{
			dp[i][j] = -1;
		}
	}
	printf("%d\n", solve(0, 0));
	return 0;
}

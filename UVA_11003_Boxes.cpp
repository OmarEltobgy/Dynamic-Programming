#include <stdio.h>
#include <algorithm>
#include <math.h>
using namespace std;

int boxesN, box[1010][2], dp[1010][3010];//0 weight 1 max load
int solve(int index, int remSize)
{
	int take=0, leave=0;
	if(remSize == 0)
	{
		return 0;
	}
	if(index == boxesN)
	{
		if(remSize >= 0)
		{
			return 0;
		}
		else
		{
			return -1000000;
		}
	}
	if(remSize < 3010 && dp[index][remSize] != -1)
	{
		return dp[index][remSize];
	}
	if(box[index][0] <= remSize)
	{
		take = 1 + solve(index+1, min(box[index][1], remSize-box[index][0]));
	}
	leave = solve(index+1, remSize);
	return dp[index][remSize] = max(take, leave);
}
int main()
{
	int i, max, temp, j;
	scanf("%d",&boxesN);
	while(boxesN != 0)
	{
		for(i=0; i<boxesN; i++)
		{
			scanf("%d %d",&box[i][0],&box[i][1]);
			for(j=0; j<3010; j++)
			{
				dp[i][j] = -1;
			}
		}
		/*max = 0;
		for(i=0; i<boxesN; i++)
		{
			temp = 1 + solve(i+1, box[i][1]);
			//printf("%d ", temp);
			if(temp > max)
			{
				max = temp;
			}
		}*/
		printf("%d\n", solve(0, 6010));
		scanf("%d",&boxesN);
	}
	return 0;
}

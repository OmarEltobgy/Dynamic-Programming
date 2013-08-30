#include <stdio.h>

int main()
{
	int testN, ttt, stationN, roadN, r, x, temp, best, bestStart, bestFinish, tempStart;
	scanf("%d",&testN);
	for(ttt=1; ttt<=testN; ttt++)
	{
		scanf("%d",&stationN);
		roadN = stationN-1;
		scanf("%d",&x);
		best = x;
		temp = x;
		tempStart = 1;
		bestStart = 1;
		bestFinish = 2;
		for(r=2; r<=roadN; r++)
		{
			scanf("%d",&x);
			if(temp + x < 0 || temp < 0)
			{
				temp = x;
				tempStart = r;
			}
			else
			{
				temp += x;
			}
			if(temp > best)
			{
				best = temp;
				bestStart = tempStart;
				bestFinish = r+1;
			}
			else if(temp == best)
			{
				if((r+1)-tempStart > bestFinish-bestStart)
				{
					bestStart = tempStart;
					bestFinish = r+1;
				}
				else if((r+1)-tempStart == bestFinish-bestStart)
				{
					if(tempStart < bestStart)
					{
						bestStart = tempStart;
						bestFinish = r+1;
					}
				}
			}
		}
		if(best > 0)
		{
			printf("The nicest part of route %d is between stops %d and %d\n", ttt, bestStart, bestFinish);
		}
		else
		{
			printf("Route %d has no nice parts\n", ttt);
		}
	}
	return 0;
}

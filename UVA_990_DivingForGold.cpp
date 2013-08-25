#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <string.h>
using namespace std;

int maxTime, w, treasureN, dp[40][1010], treasure[40][2];
int visited[40], isTaken[40][1010], result[40][2];//0 depth 1 value
int solve(int index, int remainingTime)
{
	int take=0, leave=0;
	if(index == treasureN || remainingTime == 0)
	{
		return 0;
	}
	if(dp[index][remainingTime] != -1)
	{
		return dp[index][remainingTime];
	}
	if(remainingTime-3*w*treasure[index][0] >= 0)
	{
		take = treasure[index][1] + solve(index+1, remainingTime-3*w*treasure[index][0]);
	}
	leave = solve(index+1, remainingTime);
	if(take > leave)
	{
		isTaken[index][remainingTime] = 1;
	}
	return dp[index][remainingTime] = max(take, leave);
}
int main()
{
	int i, j, maxVal, time, counter, flag=0;
	while(scanf("%d %d",&maxTime,&w) != EOF)
	{
		if(flag == 0)
		{
			flag = 1;
		}
		else
		{
			printf("\n");
		}
		scanf("%d",&treasureN);
		memset(dp, -1, sizeof(dp));
		memset(isTaken, -1, sizeof(isTaken));
		memset(visited, 0, sizeof(visited));
		for(i=0; i<treasureN; i++)
		{
			scanf("%d %d",&treasure[i][0],&treasure[i][1]);
		}
		maxVal = solve(0, maxTime);
		time = maxTime;
		printf("%d\n", maxVal);
		counter = 0;
		for(i=0; i<treasureN && time>0; i++)
		{
			//printf("%d ", dp[i][time]);
			if(isTaken[i][time] == 1)
			{
				//if(time - 3*w*treasure[i][0] >= 0 && maxVal - treasure[i][1] >= 0)
				//{
					result[counter][0] = treasure[i][0];
					result[counter][1] = treasure[i][1];
					counter ++;
					//visited[i] = 1;
					time = time - 3*w*treasure[i][0];
					//maxVal = maxVal - treasure[i][1];
					//i=-1;
				//}
			}
		}
		printf("%d\n", counter);
		for(i=0; i<counter; i++)
		{
			printf("%d %d\n", result[i][0], result[i][1]);
		}
	}
	return 0;
}

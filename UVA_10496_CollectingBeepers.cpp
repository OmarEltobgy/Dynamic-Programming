#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>
using namespace std;

int xStart, yStart, adjMat[25][25], beeper[15][2], beeperN, xSize, ySize, dp[25][25][1100];
int solve(int xIndex, int yIndex, int visited)
{
	int i, temp, best, distance;
	if(visited == ceil(pow(2, beeperN))-1)
	{
		distance = abs(xIndex-xStart) + abs(yIndex-yStart);
		return distance;
	}
	if(dp[xIndex][yIndex][visited] != -1)
	{
		return dp[xIndex][yIndex][visited];
	}
	best = 1000000;
	for(i=0; i<beeperN; i++)
	{
		//printf("%d %d\n", visited & (1<<i), visited & (1<<i)==0);
		if((visited & (1<<i)) == 0)
		{
			distance = abs(xIndex-beeper[i][0]) + abs(yIndex-beeper[i][1]);
			temp = distance + solve(beeper[i][0], beeper[i][1], (visited | (1<<i)));
			best = min(best, temp);
		}
	}
	return dp[xIndex][yIndex][visited] = best;
}
int main()
{
	int testN, i, j, x, y;
	scanf("%d",&testN);
	while(testN--)
	{
		memset(dp, -1, sizeof(dp));
		scanf("%d %d",&xSize,&ySize);
		scanf("%d %d",&x,&y);
		xStart = x-1;
		yStart = y-1;
		scanf("%d",&beeperN);
		for(i=0; i<beeperN; i++)
		{
			scanf("%d %d",&x,&y);
			beeper[i][0] = x-1;
			beeper[i][1] = y-1;
		}
		printf("The shortest path has length %d\n", solve(xStart, yStart, 0));
	}
}
